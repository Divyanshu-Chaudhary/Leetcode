#include <iostream>

// Check Divisibility by Digit Sum and Product

bool checkDivisibility(int n)
{
    int temp = n;
    int sum = 0;
    int prod = 1;
    while (temp > 0)
    {
        int rem = temp % 10;
        sum += rem;
        prod *= rem;
        temp = temp / 10;
    }
    sum += prod;
    if (n % sum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
