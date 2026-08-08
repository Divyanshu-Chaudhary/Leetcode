#include <iostream>
#include <vector>

// Find the Lexicographically Smallest Valid Sequence

vector<int> validSequence(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    // right_match[i] stores the length of the longest suffix of word2
    // that can be formed exactly using a subsequence of word1[i...n-1]
    vector<int> right_match(n + 1, 0);
    int j = m - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (j >= 0 && word1[i] == word2[j])
        {
            j--;
        }
        right_match[i] = m - 1 - j;
    }

    vector<int> ans;
    bool changed = false;
    j = 0;

    // Greedily pick the smallest indices from left to right
    for (int i = 0; i < n; ++i)
    {
        if (j == m)
            break;

        if (word1[i] == word2[j])
        {
            ans.push_back(i);
            j++;
        }
        else if (!changed && right_match[i + 1] >= m - 1 - j)
        {
            // If they don't match, we can change word1[i] to word2[j] ONLY IF
            // we haven't made a change yet AND the remaining suffix of word2
            // can be formed perfectly by the remaining suffix of word1.
            ans.push_back(i);
            j++;
            changed = true;
        }
    }

    if (j == m)
    {
        return ans;
    }
    return {}; // Return empty array if no valid sequence exists
}
