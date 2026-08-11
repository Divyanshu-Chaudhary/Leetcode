#include <iostream>
#include <vector>
#include <unordered_set>

// Smallest Missing Integer Greater Than Sequential Prefix Sum

int missingInteger(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st(begin(nums), end(nums));
    int sequential = nums[0];
    for (int j = 1; j < n; j++)
    {
        if (nums[j] == nums[j - 1] + 1)
        {
            sequential += nums[j];
        }
        else
        {
            break;
        }
    }
    while (st.count(sequential))
    {
        sequential++;
    }
    return sequential;
}
