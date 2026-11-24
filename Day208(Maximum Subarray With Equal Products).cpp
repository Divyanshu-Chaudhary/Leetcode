#include <iostream>
#include <vector>

// Maximum Subarray With Equal Products

int maxLength(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return (n == 1 && nums[0] == 1) ? 1 : 0;

    int ans = 2; // Every subarray of length 2 is always product equivalent
    long long prod = 1;
    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        // Shrink window until nums[right] is coprime with all elements in [left, right - 1]
        while (std::gcd(prod, (long long)nums[right]) > 1)
        {
            prod /= nums[left];
            left++;
        }
        prod *= nums[right];
        ans = max(ans, right - left + 1);
    }

    return ans;
}
