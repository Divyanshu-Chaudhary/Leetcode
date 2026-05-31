#include <iostream>
#include <vector>

// Count the Number of Consistent Strings

int countConsistentStrings(string allowed, vector<string> &words)
{
    int mask = 0;
    for (char &ch : allowed)
    {
        mask |= (1 << (ch - 'a'));
    }
    int count = 0;
    for (string &word : words)
    {
        bool allChar = true;
        for (char &ch : word)
        {
            if (((mask >> (ch - 'a')) & 1) == 0)
            {
                allChar = false;
                break;
            }
        }
        if (allChar)
        {
            count++;
        }
    }
    return count;
}
