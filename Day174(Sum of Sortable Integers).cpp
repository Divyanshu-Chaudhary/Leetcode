#include <iostream>
#include <vector>

// Sum of Sortable Integers

int sortableIntegers(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;

    for (int k = 1; k <= n; ++k)
    {
        // k must be a divisor of n
        if (n % k != 0)
            continue;

        bool isSortable = true;
        int prevMax = INT_MIN;

        for (int i = 0; i < n; i += k)
        {
            int drops = 0;
            int currentMin = INT_MAX;
            int currentMax = INT_MIN;

            // Analyze the current subarray of length k
            for (int j = 0; j < k; ++j)
            {
                int curr = nums[i + j];
                int next = nums[i + (j + 1) % k];

                currentMin = min(currentMin, curr);
                currentMax = max(currentMax, curr);

                // Check for a drop (including wrap-around to the start of the subarray)
                if (curr > next)
                {
                    drops++;
                }
            }

            // If there's more than 1 drop, it cannot be sorted by a cyclic shift
            if (drops > 1)
            {
                isSortable = false;
                break;
            }

            // The max of the previous subarray must be <= the min of the current subarray
            if (prevMax > currentMin)
            {
                isSortable = false;
                break;
            }

            prevMax = currentMax;
        }

        // If all subarrays are valid and correctly ordered, k is sortable
        if (isSortable)
        {
            sum += k;
        }
    }

    return sum;
}
