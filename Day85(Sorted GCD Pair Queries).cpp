#include <iostream>
#include <algorithm>
#include <vector>

// Sorted GCD Pair Queries

vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
{
    int max_val = 0;
    for (int num : nums)
    {
        if (num > max_val)
        {
            max_val = num;
        }
    }

    // Step 1: Count frequencies of each number in nums
    vector<long long> count(max_val + 1, 0);
    for (int num : nums)
    {
        count[num]++;
    }

    // Step 2: Count how many multiples of each i exist in nums
    vector<long long> multiples(max_val + 1, 0);
    for (int i = 1; i <= max_val; ++i)
    {
        for (int j = i; j <= max_val; j += i)
        {
            multiples[i] += count[j];
        }
    }

    // Step 3: Calculate exactly how many pairs have a GCD of exactly i
    vector<long long> exact_gcd(max_val + 1, 0);
    for (int i = max_val; i >= 1; --i)
    {
        // Pairs where both numbers are multiples of i
        long long pairs_with_multiple = multiples[i] * (multiples[i] - 1) / 2;

        // Subtract pairs whose exact GCD is a strict multiple of i (e.g., 2i, 3i)
        long long overcount = 0;
        for (int j = 2 * i; j <= max_val; j += i)
        {
            overcount += exact_gcd[j];
        }
        exact_gcd[i] = pairs_with_multiple - overcount;
    }

    // Step 4: Compute prefix sums of the exact GCD frequencies
    vector<long long> prefix_sums(max_val + 1, 0);
    for (int i = 1; i <= max_val; ++i)
    {
        prefix_sums[i] = prefix_sums[i - 1] + exact_gcd[i];
    }

    // Step 5: Answer each query using binary search
    vector<int> ans;
    ans.reserve(queries.size());
    for (long long q : queries)
    {
        // Find the first GCD whose cumulative pair count is > q
        auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
        ans.push_back(distance(prefix_sums.begin(), it));
    }

    return ans;
}
