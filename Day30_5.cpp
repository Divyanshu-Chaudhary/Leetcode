#include <iostream>
#include <vector>

int solve(vector<int> &nums, int i, int Xor)
{
    if (i == nums.size())
    {
        return Xor;
    }

    int include = solve(nums, i + 1, nums[i] ^ Xor);
    int exclude = solve(nums, i + 1, Xor);
    return include + exclude;
}

int subsetXORSum(vector<int> &nums)
{
    // return solve(nums, 0, 0);

    int n = nums.size();
    int result = 0;
    for (int &num : nums)
    {
        result |= num;
    }
    return result << (n - 1);
}
