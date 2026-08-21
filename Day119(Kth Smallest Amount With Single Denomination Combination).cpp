#include <iostream>
#include <vector>

// Kth Smallest Amount With Single Denomination Combination

long long findKthSmallest(vector<int> &coins, int k)
{
    int n = coins.size();
    vector<pair<long long, int>> lcm_subsets;

    // Precompute the LCM for all non-empty subsets of coins
    for (int i = 1; i < (1 << n); ++i)
    {
        long long current_lcm = 1;
        int set_bits = 0;

        for (int j = 0; j < n; ++j)
        {
            if ((i >> j) & 1)
            {
                current_lcm = std::lcm(current_lcm, (long long)coins[j]);
                set_bits++;
            }
        }

        // PIE: odd subsets are added (+1), even subsets are subtracted (-1)
        int sign = (set_bits % 2 == 1) ? 1 : -1;
        lcm_subsets.push_back({current_lcm, sign});
    }

    // Binary search bounds
    long long min_c = coins[0];
    for (int c : coins)
        min_c = min((long long)c, min_c);

    long long left = 1;
    long long right = (long long)k * min_c;
    long long ans = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long count = 0;

        // Count how many amounts <= mid can be formed
        for (const auto &subset : lcm_subsets)
        {
            count += subset.second * (mid / subset.first);
        }

        if (count >= k)
        {
            ans = mid;
            right = mid - 1; // Try to find a smaller valid amount
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}
