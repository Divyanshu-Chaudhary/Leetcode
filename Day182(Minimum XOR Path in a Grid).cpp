#include <iostream>
#include <vector>

// Minimum XOR Path in a Grid

int minCost(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // dp[i][j][x] = true if XOR value x is achievable
    // at cell (i, j).
    vector<vector<bitset<1024>>> dp(
        m, vector<bitset<1024>>(n));

    // Starting cell contributes its own value.
    dp[0][0].set(grid[0][0]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
                continue;

            // Reach current cell from above.
            if (i > 0)
            {
                for (int x = 0; x < 1024; x++)
                {
                    if (dp[i - 1][j].test(x))
                    {
                        dp[i][j].set(x ^ grid[i][j]);
                    }
                }
            }

            // Reach current cell from the left.
            if (j > 0)
            {
                for (int x = 0; x < 1024; x++)
                {
                    if (dp[i][j - 1].test(x))
                    {
                        dp[i][j].set(x ^ grid[i][j]);
                    }
                }
            }
        }
    }

    // Find the smallest achievable XOR at the destination.
    for (int x = 0; x < 1024; x++)
    {
        if (dp[m - 1][n - 1].test(x))
        {
            return x;
        }
    }

    return -1;
}
