#include <iostream>
#include <vector>

// Sum Game

bool sumGame(string num)
{
    int n = num.length();
    int sum_diff = 0; // S_L - S_R
    int q_diff = 0;   // C_L - C_R

    // Process the first half of the string
    for (int i = 0; i < n / 2; ++i)
    {
        if (num[i] == '?')
        {
            q_diff++;
        }
        else
        {
            sum_diff += (num[i] - '0');
        }
    }

    // Process the second half of the string
    for (int i = n / 2; i < n; ++i)
    {
        if (num[i] == '?')
        {
            q_diff--;
        }
        else
        {
            sum_diff -= (num[i] - '0');
        }
    }

    // If the total number of '?' is odd, Alice wins.
    // (Note: (C_L + C_R) % 2 is mathematically equivalent to (C_L - C_R) % 2)
    if (q_diff % 2 != 0)
    {
        return true;
    }

    // Check if Bob's forced sum condition holds true
    return sum_diff + (q_diff / 2) * 9 != 0;
}
