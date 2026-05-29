#include <iostream>
#include <vector>

// Make Two Arrays Equal by Reversing Subarrays

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    int n = target.size();
    sort(begin(target), end(target));
    sort(begin(arr), end(arr));

    for (int i = 0; i < n; i++)
    {
        if (target[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}
