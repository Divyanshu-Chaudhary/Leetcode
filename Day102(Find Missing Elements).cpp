#include <iostream>
#include <vector>

// Find Missing Elements

vector<int> findMissingElements(vector<int> &nums)
{
    vector<int> output;
    sort(nums.begin(), nums.end());
    int start = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        start++;
        while (start < nums[i])
        {
            output.push_back(start);
            start++;
        }
    }
    return output;
}
