#include <iostream>
#include <vector>
#include <string>

// Reverse Substrings Between Each Pair of Parentheses

string reverseParentheses(string s)
{
    vector<int> open_paren_indices;
    string result = "";

    for (char c : s)
    {
        if (c == '(')
        {
            // Store the current length of the result string.
            // This will be the start index of the substring to reverse.
            open_paren_indices.push_back(result.length());
        }
        else if (c == ')')
        {
            // Get the start index of the most recent open parenthesis
            int start = open_paren_indices.back();
            open_paren_indices.pop_back();
            // Reverse the substring from 'start' to the end of the current result
            reverse(result.begin() + start, result.end());
        }
        else
        {
            // Append lowercase English letters directly to the result
            result += c;
        }
    }

    return result;
}
