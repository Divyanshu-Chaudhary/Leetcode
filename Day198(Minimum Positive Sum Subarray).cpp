#include <iostream>
#include <vector>

// Minimum Positive Sum Subarray

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int n = nums.size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n && j - i + 1 <= r; j++)
        {
            sum += nums[j];

            int len = j - i + 1;

            // Check if length is valid and sum is positive
            if (len >= l && sum > 0)
            {
                ans = min(ans, sum);
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
