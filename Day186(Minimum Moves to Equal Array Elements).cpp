#include <iostream>
#include <vector>

// Minimum Moves to Equal Array Elements

int minMoves(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;
    int min_el = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        min_el = min(min_el, nums[i]);
    }

    return sum - n * min_el;
}
