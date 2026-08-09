#include <iostream>
#include <vector>

// Minimum Number of Operations to Make Elements in Array Distinct

int minimumOperations(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.count(nums[i]))
        {
            return ceil((i + 1) / 3.0);
        }
        st.insert(nums[i]);
    }
    return 0;
}
