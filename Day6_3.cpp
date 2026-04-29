#include <iostream>
#include <vector>
using namespace std;

long long maximumScore(vector<vector<int>> &grid)
{
    int n = grid.size();

    // pref[i][j] stores the sum of the first 'i' elements in column 'j'
    vector<vector<long long>> pref(n + 1, vector<long long>(n, 0));
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            pref[i + 1][j] = pref[i][j] + grid[i][j];
        }
    }

    const long long INF = 1e18;
    // dp[p][c] = max score for suffix of columns given L_{j-1} = p, L_j = c
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));

    // Base case: for the very last imaginary column (j = n), its height is strictly 0.
    for (int c = 0; c <= n; ++c)
    {
        dp[c][0] = 0;
    }

    // Process columns from right to left
    for (int j = n - 1; j >= 0; --j)
    {
        vector<vector<long long>> new_dp(n + 1, vector<long long>(n + 1, -INF));

        // Fix the height of the current column (c)
        for (int c = 0; c <= n; ++c)
        {

            // --- $O(1)$ Transition Optimization using Prefix & Suffix Maximums ---

            // 1. Prefix max for cases where next column <= left column (nxt <= p)
            vector<long long> pref_max_V(n + 1, -INF);
            long long current_max = -INF;
            for (int nxt = 0; nxt <= n; ++nxt)
            {
                current_max = max(current_max, dp[c][nxt]);
                pref_max_V[nxt] = current_max;
            }

            // 2. Suffix max for cases where next column > left column (nxt > p)
            vector<long long> suff_max_V(n + 2, -INF);
            current_max = -INF;
            for (int nxt = n; nxt >= 0; --nxt)
            {
                long long val_nxt = max(0LL, pref[nxt][j] - pref[c][j]);
                if (dp[c][nxt] != -INF)
                {
                    current_max = max(current_max, val_nxt + dp[c][nxt]);
                }
                suff_max_V[nxt] = current_max;
            }

            // Now compute new_dp[p][c] in O(1) for all possible left column heights (p)
            for (int p = 0; p <= n; ++p)
            {
                // Cost if nxt <= p
                long long val_p = max(0LL, pref[p][j] - pref[c][j]);
                long long op1 = -INF;
                if (pref_max_V[p] != -INF)
                {
                    op1 = val_p + pref_max_V[p];
                }

                // Cost if nxt > p
                long long op2 = suff_max_V[p + 1];

                // Take the best of both scenarios
                new_dp[p][c] = max(op1, op2);
            }
        }
        dp = new_dp; // Move to the next column
    }

    // The answer is the max score at column 0, assuming an imaginary left column of height 0
    long long ans = 0;
    for (int c = 0; c <= n; ++c)
    {
        ans = max(ans, dp[0][c]);
    }

    return ans;
}

int main()
{
    return 0;
}