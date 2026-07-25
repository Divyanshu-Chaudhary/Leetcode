#include <iostream>
#include <vector>

// Maximum Product of Two Digits

int maxProduct(int n)
{
    vector<int> digitArray;
    // Handle edge case for zero
    if (n == 0)
    {
        return 0;
    }

    // Extract digits from right to left
    while (n > 0)
    {
        digitArray.push_back(n % 10); // Gets the last digit
        n /= 10;                      // Removes the last digit
    }
    sort(digitArray.begin(), digitArray.end(), greater<int>());
    return digitArray[0] * digitArray[1];
}
