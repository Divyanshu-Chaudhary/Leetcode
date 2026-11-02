#include <iostream>
#include <vector>

// Minimum Moves to Equal Array Elements II

int minMoves2(vector<int> &nums)
{
    int n = nums.size();

    sort(begin(nums), end(nums));

    int mid = nums[n / 2];

    int moves = 0;
    for (int i = 0; i < n; i++)
    {
        moves += abs(nums[i] - mid);
    }

    return moves;
}
