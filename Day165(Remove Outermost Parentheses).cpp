#include <iostream>
#include <string>

// Remove Outermost Parentheses

string removeOuterParentheses(string s)
{
    int count = 0;

    string result = "";

    for (char &ch : s)
    {
        if (ch == '(')
        {
            if (count != 0)
                result.push_back(ch);

            count++;
        }
        else
        {
            count--;
            if (count != 0)
                result.push_back(ch);
        }
    }

    return result;
}
