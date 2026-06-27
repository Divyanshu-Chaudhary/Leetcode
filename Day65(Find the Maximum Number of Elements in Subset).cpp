#include <iostream>
#include <vector>

// Find the Maximum Number of Elements in Subset

int maximumLength(vector<int> &nums)
{
    unordered_map<long long, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }

    int maxLength = 1; // Minimum possible length is always 1 (picking a single element)

    // Special case handling for 1
    if (freq.count(1))
    {
        int countOnes = freq[1];
        // The length for 1s must be odd
        if (countOnes % 2 == 0)
        {
            countOnes--;
        }
        maxLength = max(maxLength, countOnes);
    }

    // Check for all other numbers
    for (auto &[val, count] : freq)
    {
        if (val == 1)
            continue;
        if (count < 2)
            continue; // We need at least 2 copies to start a sequence slope

        long long curr = val;
        int currentLength = 0;

        // Keep climbing the powers sequence as long as we have pairs
        while (freq.count(curr) && freq[curr] >= 2)
        {
            currentLength += 2;
            curr *= curr; // Square the current number
        }

        // Determine the peak of this subset
        if (freq.count(curr) && freq[curr] >= 1)
        {
            currentLength += 1; // The sequence successfully caps off with a peak
        }
        else
        {
            currentLength -= 1; // The previous element has to act as the peak, reducing size by 1
        }

        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}
