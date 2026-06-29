#include <iostream>
#include <vector>

// Number of Strings That Appear as Substrings in Word

int numOfStrings(vector<string> &patterns, string word)
{
    int count = 0;

    // Iterate through each string in the patterns array
    for (const string &pattern : patterns)
    {
        // Check if the pattern exists as a substring in 'word'
        if (word.find(pattern) != string::npos)
        {
            count++;
        }
    }

    return count;
}
