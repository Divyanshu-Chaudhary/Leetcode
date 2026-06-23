#include <iostream>
#include <vector>

// Number of ZigZag Arrays I

int zigZagArrays(int n, int l, int r)
{
    int MOD = 1e9 + 7;
    int m = r - l;

    // dp[v] will store the number of valid zigzag sequences
    // of the current length that end with the value v.
    vector<int> dp(m + 1, 1);

    for (int i = 1; i < n; i++)
    {
        int pre = 0;

        if (i % 2 == 1)
        {
            // Going UP: We need the previous element to be strictly less than the current one.
            // We maintain a running sum of all previous valid states (prefix sum).
            for (int v = 0; v <= m; v++)
            {
                int next_pre = (pre + dp[v]) % MOD;
                dp[v] = pre;
                pre = next_pre;
            }
        }
        else
        {
            // Going DOWN: We need the previous element to be strictly greater than the current one.
            // We maintain a running sum from the top down (suffix sum).
            for (int v = m; v >= 0; v--)
            {
                int next_pre = (pre + dp[v]) % MOD;
                dp[v] = pre;
                pre = next_pre;
            }
        }
    }

    // Sum up all the valid paths that started with an UP sequence.
    int ans = 0;
    for (int count : dp)
    {
        ans = (ans + count) % MOD;
    }

    // Multiply by 2 because for every valid sequence that starts with an UP move,
    // there is a perfectly symmetrical valid sequence that starts with a DOWN move.
    return (ans * 2LL) % MOD;
}