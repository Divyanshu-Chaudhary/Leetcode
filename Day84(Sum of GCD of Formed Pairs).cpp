#include <iostream>
#include <vector>

// Sum of GCD of Formed Pairs

long long gcdSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> prefixGcd(n);
    int current_max = 0;

    // Step 1: Construct the prefixGcd array
    for (int i = 0; i < n; ++i)
    {
        current_max = max(current_max, nums[i]);
        prefixGcd[i] = std::gcd(nums[i], current_max);
    }

    // Step 2: Sort in non-decreasing order
    sort(prefixGcd.begin(), prefixGcd.end());

    // Step 3 & 4: Form pairs and sum their GCDs
    long long totalSum = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        totalSum += std::gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }

    return totalSum;
}
