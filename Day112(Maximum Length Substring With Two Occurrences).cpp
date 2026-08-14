#include <iostream>
#include <string>
#include <vector>

// Maximum Length Substring With Two Occurrences

int maximumLengthSubstring(string s)
{
    vector<int> count(26, 0);
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right)
    {
        count[s[right] - 'a']++;

        // Shrink the window from the left until the count is at most 2
        while (count[s[right] - 'a'] > 2)
        {
            count[s[left] - 'a']--;
            left++;
        }

        // Update the maximum valid window length
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}
