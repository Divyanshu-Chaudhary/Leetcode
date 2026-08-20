#include <iostream>
#include <vector>

// Distribute Elements Into Two Arrays I

vector<int> resultArray(vector<int> &nums)
{
    vector<int> arr1;
    vector<int> arr2;

    // Operation 1 and 2: distribute the first two elements
    arr1.push_back(nums[0]);
    if (nums.size() > 1)
    {
        arr2.push_back(nums[1]);
    }

    // Distribute the rest of the elements based on the condition
    for (int i = 2; i < nums.size(); ++i)
    {
        if (arr1.back() > arr2.back())
        {
            arr1.push_back(nums[i]);
        }
        else
        {
            arr2.push_back(nums[i]);
        }
    }

    // Concatenate arr2 to the end of arr1
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());

    return arr1;
}
