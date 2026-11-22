#include <iostream>
#include <string>

// Check if All A's Appears Before All B's

bool checkString(string s)
{
    int n = s.length();

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'b' && s[i] == 'a')
            return false;
    }
    return true;
}
