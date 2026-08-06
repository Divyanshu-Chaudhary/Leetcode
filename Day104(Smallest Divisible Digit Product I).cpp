#include <iostream>
#include <vector>

// Smallest Divisible Digit Product I

int smallestNumber(int n, int t)
{
    while (true)
    {
        int temp = n;
        int digitProduct = 1;

        // Calculate the product of the digits
        while (temp > 0)
        {
            digitProduct *= (temp % 10);
            temp /= 10;
        }

        // Check if the product is divisible by t
        if (digitProduct % t == 0)
        {
            return n;
        }

        // Increment n to check the next number
        n++;
    }
}