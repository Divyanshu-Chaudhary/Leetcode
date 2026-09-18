#include <iostream>
#include <vector>

// Maximum Number of Non-Overlapping Substrings

vector<string> maxNumOfSubstrings(string s)
{
    int n = s.length();
    vector<int> first(26, -1), last(26, -1);

    // Step 1: Record the first and last occurrence of each character
    for (int i = 0; i < n; ++i)
    {
        if (first[s[i] - 'a'] == -1)
        {
            first[s[i] - 'a'] = i;
        }
        last[s[i] - 'a'] = i;
    }

    struct Interval
    {
        int l, r;
    };
    vector<Interval> intervals;

    // Step 2: Find all valid intervals starting at the first occurrence of a character
    for (int i = 0; i < 26; ++i)
    {
        if (first[i] != -1)
        {
            int l = first[i];
            int r = last[i];
            bool isValid = true;

            for (int j = l; j <= r; ++j)
            {
                // If a character inside our bounds appeared before 'l',
                // this interval is invalid as it would need to stretch backwards.
                if (first[s[j] - 'a'] < l)
                {
                    isValid = false;
                    break;
                }
                // Expand the right boundary to include all occurrences of the current character
                r = max(r, last[s[j] - 'a']);
            }

            if (isValid)
            {
                intervals.push_back({l, r});
            }
        }
    }

    // Step 3: Sort intervals. Primary: end index (asc). Secondary: start index (desc).
    // Sorting by end index handles maximizing count; picking larger start index handles minimizing length.
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
         {
            if (a.r != b.r) return a.r < b.r;
            return a.l > b.l; });

    // Step 4: Greedily pick non-overlapping intervals
    vector<string> result;
    int prev_end = -1;

    for (const auto &interval : intervals)
    {
        if (interval.l > prev_end)
        {
            result.push_back(s.substr(interval.l, interval.r - interval.l + 1));
            prev_end = interval.r;
        }
    }

    return result;
}
