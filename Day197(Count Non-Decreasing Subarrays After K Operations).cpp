#include <iostream>
#include <vector>
#include <deque>

// Count Non-Decreasing Subarrays After K Operations

long long countNonDecreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();

    deque<int> dq;
    long long cost = 0;
    long long ans = 0;

    int j = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {

        // Merge smaller elements into the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {

            int l = dq.back();
            dq.pop_back();

            int r = dq.empty() ? j + 1 : dq.back();

            // Increase all elements in this segment
            cost += (long long)(r - l) * (nums[i] - nums[l]);
        }

        // Insert current index
        dq.push_back(i);

        // Shrink window if operations exceed k
        while (cost > k)
        {

            cost -= (long long)nums[dq.front()] - nums[j];

            if (dq.front() == j)
            {
                dq.pop_front();
            }

            j--;
        }

        // Count valid subarrays starting at i
        ans += j - i + 1;
    }

    return ans;
}
