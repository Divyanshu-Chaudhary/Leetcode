#include <iostream>
#include <vector>

int maxProduct(vector<int> &nums)
{
    int currMax = nums[0];
    int result = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = (currMax - 1) * (nums[i] - 1);
        result = max(result, temp);
        currMax = max(currMax, nums[i]);
    }
    return result;
}

int main()
{
    return 0;
}