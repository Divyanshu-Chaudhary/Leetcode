#include <iostream>

// Count the Number of Special Characters II

int numberOfSpecialChars(string word)
{
    int n = word.length();
    int count = 0;
    vector<int> last(26, -1);
    vector<int> first(26, -1);

    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (islower(ch))
        {
            last[ch - 'a'] = i;
        }
        else
        {
            if (first[ch - 'A'] == -1)
            {
                first[ch - 'A'] = i;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (last[i] != -1 && first[i] != -1 && last[i] < first[i])
        {
            count++;
        }
    }
    return count;
}
