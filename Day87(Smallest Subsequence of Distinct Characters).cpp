#include <iostream>
#include <vector>
#include <string>

// Smallest Subsequence of Distinct Characters

string smallestSubsequence(string s)
{
    vector<int> last_pos(26, 0);
    vector<bool> visited(26, false);
    string result = "";

    // Step 1: Record the last occurrence of each character
    for (int i = 0; i < s.length(); ++i)
    {
        last_pos[s[i] - 'a'] = i;
    }

    // Step 2: Iterate and build the optimal sequence
    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];

        // If the character is already in our constructed sequence, skip it
        if (visited[c - 'a'])
        {
            continue;
        }

        // Maintain the lexicographically smallest property:
        // Pop characters that are greater than the current one IF they appear again later
        while (!result.empty() && result.back() > c && last_pos[result.back() - 'a'] > i)
        {
            visited[result.back() - 'a'] = false;
            result.pop_back();
        }

        // Append current character and mark as visited
        result.push_back(c);
        visited[c - 'a'] = true;
    }

    return result;
}
