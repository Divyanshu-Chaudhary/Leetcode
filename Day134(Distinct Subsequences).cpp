#include <iostream>
#include <vector>

// Distinct Subsequences

int numDistinct(string s, string t)
{
    int m = s.length();
    int n = t.length();

    // Use unsigned long long to avoid intermediate integer overflow
    // during C++ test case evaluation
    vector<unsigned long long> dp(n + 1, 0);

    // Base case: 1 way to match an empty string 't'
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        // Traverse backwards for 1D space optimization
        for (int j = n; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }

    return dp[n];
}
