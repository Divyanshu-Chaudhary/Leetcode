#include <iostream>
#include <string>

// Maximize Sum of Squares of Digits

string maxSumOfSquares(int num, int sum)
{
    // If the required sum is larger than the maximum possible sum with 'num' digits
    if (sum > num * 9)
    {
        return "";
    }

    int nines = sum / 9;
    int rem = sum % 9;
    int zeros = num - nines - (rem > 0 ? 1 : 0);

    std::string ans = "";

    // Greedily append the largest digits first to maximize the integer itself
    if (nines > 0)
    {
        ans += std::string(nines, '9');
    }
    if (rem > 0)
    {
        ans += std::to_string(rem);
    }
    if (zeros > 0)
    {
        ans += std::string(zeros, '0');
    }

    return ans;
}
