#include <iostream>
#include <vector>
#include <string>

// Maximum Nesting Depth of Two Valid Parentheses Strings

vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> ans;
    int depth = 0;
    for (char c : seq)
    {
        if (c == '(')
        {
            depth++;
            ans.push_back(depth % 2);
        }
        else
        {
            ans.push_back(depth % 2);
            depth--;
        }
    }
    return ans;
}
