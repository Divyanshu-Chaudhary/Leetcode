#include <iostream>

// Total Waviness of Numbers in Range II

struct Result
{
    long long count;
    long long waviness;
};
string S;
Result memo[20][2][2][11][11];
bool visited[20][2][2][11][11];

// prev1 is index-1, prev2 is index-2
// Use 10 to represent "no digit yet"
Result dp(int idx, bool tight, bool leading_zeros, int p1, int p2)
{
    if (idx == S.size())
    {
        return {1, 0};
    }
    if (visited[idx][tight][leading_zeros][p1][p2])
    {
        return memo[idx][tight][leading_zeros][p1][p2];
    }

    Result res = {0, 0};
    int limit = tight ? (S[idx] - '0') : 9;

    for (int digit = 0; digit <= limit; ++digit)
    {
        bool next_tight = tight && (digit == limit);
        bool next_leading = leading_zeros && (digit == 0);

        int next_p1 = next_leading ? 10 : digit;
        int next_p2 = next_leading ? 10 : p1;

        Result next_res = dp(idx + 1, next_tight, next_leading, next_p1, next_p2);

        long long current_waviness = 0;
        // Check if p1 is a peak or valley
        if (p1 != 10 && p2 != 10 && !leading_zeros)
        {
            if ((p1 > p2 && p1 > digit) || (p1 < p2 && p1 < digit))
            {
                current_waviness = 1;
            }
        }

        res.count += next_res.count;
        res.waviness += next_res.waviness + (current_waviness * next_res.count);
    }

    visited[idx][tight][leading_zeros][p1][p2] = true;
    return memo[idx][tight][leading_zeros][p1][p2] = res;
}

long long solve(long long n)
{
    if (n < 100)
        return 0;
    S = to_string(n);
    memset(visited, 0, sizeof(visited));
    return dp(0, true, true, 10, 10).waviness;
}

long long totalWaviness(long long num1, long long num2)
{
    return solve(num2) - solve(num1 - 1);
}
