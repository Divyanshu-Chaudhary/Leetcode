#include <iostream>

// Concatenate Non-Zero Digits and Multiply by Sum I

long long sumAndMultiply(int n)
{
    string n_str = to_string(n);
    int s = n_str.size();
    long num = 0;
    long sum = 0;
    for (int i = 0; i < s; i++)
    {
        if (n_str[i] != '0')
        {
            sum += (n_str[i] - '0');
            num = num * 10 + (n_str[i] - '0');
        }
    }
    return (num * sum);
}
