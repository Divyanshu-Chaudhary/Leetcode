#include <iostream>
#include <vector>

int minOperations(string s)
{
    int startZero = 0;
    int startOne = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '0')
            {
                startOne++;
            }
            else
            {
                startZero++;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                startZero++;
            }
            else
            {
                startOne++;
            }
        }
    }
    return min(startOne, startZero);
}