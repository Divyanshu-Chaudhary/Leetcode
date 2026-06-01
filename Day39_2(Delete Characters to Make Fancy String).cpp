#include <iostream>

// Delete Characters to Make Fancy String

string makeFancyString(string s)
{
    int n = s.length();
    string out = "";
    out.push_back(s[0]);
    int freq = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == out.back())
        {
            freq++;
            if (freq < 3)
            {
                out.push_back(s[i]);
            }
        }
        else
        {
            out.push_back(s[i]);
            freq = 1;
        }
    }
    return out;
}
