#include <iostream>
#include <string>

// Score of Parentheses

int scoreOfParentheses(string s)
{
    int score = 0;
    int depth = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            depth++;
        }
        else
        {
            depth--;
            // Only add to the score if it's an innermost `()` pair
            if (s[i - 1] == '(')
            {
                score += 1 << depth; // equivalent to 2^depth
            }
        }
    }

    return score;
}
