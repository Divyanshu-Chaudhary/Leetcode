#include <iostream>
#include <string>

// Minimum Operations to Sort a String

int minOperations(string s)
{
    int n = s.length();

    // 1. Check if the string is already sorted
    bool is_sorted = true;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] < s[i - 1])
        {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted)
        return 0;

    // 2. Base case for impossible lengths
    if (n == 2)
        return -1;

    // Find the overall minimum and maximum characters
    char min_c = s[0];
    char max_c = s[0];
    for (char c : s)
    {
        if (c < min_c)
            min_c = c;
        if (c > max_c)
            max_c = c;
    }

    // 3. One operation condition
    if (s[0] == min_c || s[n - 1] == max_c)
    {
        return 1;
    }

    // 4. Three operations condition
    bool min_only_at_end = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == min_c)
        {
            min_only_at_end = false;
            break;
        }
    }

    bool max_only_at_start = true;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == max_c)
        {
            max_only_at_start = false;
            break;
        }
    }

    if (s[0] == max_c && s[n - 1] == min_c && min_only_at_end && max_only_at_start)
    {
        return 3;
    }

    // 5. Two operations for all other valid conditions
    return 2;
}
