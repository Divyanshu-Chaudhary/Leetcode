#include <iostream>
#include <vector>

// Twisted Mirror Path Count

int uniquePaths(vector<vector<int>> &grid)
{
    const int MOD = 1e9 + 7;

    int m = grid.size();
    int n = grid[0].size();

    // dp[i][j][0] = ways arriving while moving right
    // dp[i][j][1] = ways arriving while moving down
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(2, 0)));

    // Initialize start only once
    dp[0][0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            for (int dir = 0; dir < 2; dir++)
            {

                long long ways = dp[i][j][dir];

                if (ways == 0)
                    continue;

                if (grid[i][j] == 0)
                {

                    // Empty cell: can move right
                    if (j + 1 < n)
                    {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;
                    }

                    // Empty cell: can move down
                    if (i + 1 < m)
                    {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                    }
                }
                else
                {

                    if (dir == 0)
                    {
                        // Entered mirror while moving right.
                        // Reflection sends robot DOWN.

                        if (i + 1 < m)
                        {
                            dp[i + 1][j][1] =
                                (dp[i + 1][j][1] + ways) % MOD;
                        }
                    }
                    else
                    {
                        // Entered mirror while moving down.
                        // Reflection sends robot RIGHT.

                        if (j + 1 < n)
                        {
                            dp[i][j + 1][0] =
                                (dp[i][j + 1][0] + ways) % MOD;
                        }
                    }
                }
            }
        }
    }

    return (dp[m - 1][n - 1][0] +
            dp[m - 1][n - 1][1]) %
           MOD;
}
