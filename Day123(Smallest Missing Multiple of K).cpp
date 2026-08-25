#include <iostream>
#include <vector>

// Smallest Missing Multiple of K

int missingMultiple(vector<int> &nums, int k)
{
    int temp = k;
    while (true)
    {
        auto it = find(nums.begin(), nums.end(), temp);
        if (it != nums.end())
        {
            temp += k;
        }
        else
        {
            return temp;
        }
    }
    return temp;
}
