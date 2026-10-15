#include <iostream>
#include <vector>
#include <unordered_set>

// Subarrays Distinct Element Sum of Squares I

int sumCounts(vector<int> &nums)
{
    int total_sum = 0;
    int n = nums.size();

    // Iterate through all possible starting points of subarrays
    for (int i = 0; i < n; ++i)
    {
        std::unordered_set<int> distinct_elements;

        // Expand the subarray and count distinct elements
        for (int j = i; j < n; ++j)
        {
            distinct_elements.insert(nums[j]);
            int count = distinct_elements.size();
            total_sum += count * count; // Add the square of distinct counts
        }
    }

    return total_sum;
}
