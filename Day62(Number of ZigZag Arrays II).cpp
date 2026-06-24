#include <iostream>
#include <vector>

// Number of ZigZag Arrays II

int zigZagArrays(int n, int l, int r)
{
    long long MOD = 1e9 + 7;
    long long m = r - l + 1;

    // Base case: length 1 sequence (no adjacent elements to check)
    if (n == 1)
        return m % MOD;

    long long total_up_starting = 0;

    // Route 1: Matrix Exponentiation for small range M and large N
    // Time Complexity: O(M^3 log N)
    if (m <= 500)
    {
        int sz = m;
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        // Build the transition matrix
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                if (i + j >= sz)
                {
                    T[i][j] = 1;
                }
            }
        }

        auto multiply = [&](const vector<vector<long long>> &A, const vector<vector<long long>> &B)
        {
            vector<vector<long long>> C(sz, vector<long long>(sz, 0));
            for (int i = 0; i < sz; ++i)
            {
                for (int k = 0; k < sz; ++k)
                {
                    if (!A[i][k])
                        continue;
                    for (int j = 0; j < sz; ++j)
                    {
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return C;
        };

        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i)
            res[i][i] = 1;

        long long p = n - 1;
        while (p > 0)
        {
            if (p & 1)
                res = multiply(res, T);
            T = multiply(T, T);
            p >>= 1;
        }

        // Initial state v_0 = [1, 1, ..., 1]^T
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                total_up_starting = (total_up_starting + res[i][j]) % MOD;
            }
        }
    }
    // Route 2: Space-optimized DP for smaller N (or when M is huge)
    // Time Complexity: O(N * M)
    else
    {
        vector<long long> dp(m, 1);
        for (int i = 2; i <= n; ++i)
        {
            vector<long long> next_dp(m, 0);
            long long current_sum = 0;
            for (int j = 0; j < m; ++j)
            {
                next_dp[j] = current_sum;
                current_sum = (current_sum + dp[m - 1 - j]) % MOD;
            }
            dp = next_dp;
        }

        for (long long x : dp)
        {
            total_up_starting = (total_up_starting + x) % MOD;
        }
    }

    // Multiply by 2 to account for both UP-starting and DOWN-starting sequences
    return (total_up_starting * 2) % MOD;
}
