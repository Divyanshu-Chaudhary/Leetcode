#include <iostream>
#include <string>

// Calculate Digit Sum of a String

string digitSum(string s, int k)
{
    while (s.length() > k)
    {
        string temp = "";
        for (int i = 0; i < s.length(); i += k)
        {
            int sum = 0;
            for (int j = i; j < min(i + k, (int)s.length()); j++)
            {
                sum += s[j] - '0';
            }
            temp += to_string(sum);
        }
        s = temp;
    }
    return s;
}
