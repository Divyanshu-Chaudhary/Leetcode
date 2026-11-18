#include <iostream>
#include <vector>

// Minimum Number of Changes to Make Binary String Beautiful

int minChanges(string s)
{
    int changes = 0;
    int n = s.length();

    for (int i = 0; i < n; i += 2)
    {

        if (s[i] != s[i + 1])
        {
            changes++;
        }
    }

    return changes;
}
