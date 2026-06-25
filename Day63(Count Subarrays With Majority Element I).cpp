#include <iostream>
#include <vector>

// Count Subarrays With Majority Element I

int countMajoritySubarrays(vector<int> &nums, int target)
{
    int n = nums.size();

    // Since prefix sums can range from -N to N, we use an array of size 2N + 1
    // and shift all indices by 'offset' to avoid negative index access.
    vector<int> freq(2 * n + 1, 0);
    int offset = n;

    freq[offset] = 1; // Base case: prefix sum of 0 at the start

    int curr_sum = 0;
    int count_smaller = 0;
    long long ans = 0;

    for (int num : nums)
    {
        if (num == target)
        {
            // If sum increases by 1, the new strictly smaller values include
            // everything that was strictly smaller before, PLUS the values
            // equal to the old sum.
            count_smaller += freq[curr_sum + offset];
            curr_sum++;
        }
        else
        {
            // If sum decreases by 1, the new strictly smaller values exclude
            // the values that are equal to the new sum.
            count_smaller -= freq[curr_sum - 1 + offset];
            curr_sum--;
        }

        ans += count_smaller;
        freq[curr_sum + offset]++;
    }

    return ans;
}
