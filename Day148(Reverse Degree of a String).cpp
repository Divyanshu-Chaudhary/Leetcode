#include <iostream>
#include <string>
#include <vector>

// Reverse Degree of a String

int reverseDegree(string s)
{
    long long total_degree = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int reversed_pos = 26 - (s[i] - 'a');
        total_degree += reversed_pos * (i + 1);
    }
    return total_degree;
}
