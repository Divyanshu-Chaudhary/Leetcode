#include <iostream>
#include <vector>

// Maximum K to Sort a Permutation

int sortPermutation(vector<int> &nums)
{
    int k = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != i)
        {
            if (k == -1)
            {
                k = nums[i] & i;
            }
            else
            {
                k &= nums[i] & i;
            }
        }
    }
    return k == -1 ? 0 : k;
}
