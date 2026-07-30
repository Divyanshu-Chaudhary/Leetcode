#include <iostream>
#include <string>

// Minimum Number of Pushes to Type Word I

int minimumPushes(string word)
{
    int totalPushes = 0;
    for (int i = 0; i < word.length(); i++)
    {
        // (i / 8) + 1 gives the number of pushes needed for the i-th character
        totalPushes += (i / 8) + 1;
    }
    return totalPushes;
}
