#include <iostream>
#include <vector>
#include <unordered_map>

// Find the Largest Almost Missing Integer

int largestInteger(vector<int> &nums, int k)
{
    unordered_map<int, int> subarrayCount;
    int n = nums.size();

    // Loop through all possible starting indices for a subarray of size k
    for (int i = 0; i <= n - k; ++i)
    {
        unordered_set<int> currentSubarrayElements;

        // Collect unique elements in the current subarray
        for (int j = i; j < i + k; ++j)
        {
            currentSubarrayElements.insert(nums[j]);
        }

        // Increment the count for each unique element found in this subarray
        for (int num : currentSubarrayElements)
        {
            subarrayCount[num]++;
        }
    }

    int maxAlmostMissing = -1;

    // Find the largest integer that appears in exactly one subarray
    for (const auto &pair : subarrayCount)
    {
        if (pair.second == 1)
        {
            maxAlmostMissing = max(maxAlmostMissing, pair.first);
        }
    }

    return maxAlmostMissing;
}
