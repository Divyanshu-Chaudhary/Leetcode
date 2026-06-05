#include <iostream>
#include <vector>

// Maximum Ascending Subarray Sum

int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size();
    int sum = nums[0];
    int maxSum = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            sum += nums[i];
        }
        else
        {
            maxSum = max(maxSum, sum);
            sum = nums[i];
        }
    }
    return max(maxSum, sum);
}
