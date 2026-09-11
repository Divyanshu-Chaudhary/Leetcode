#include <iostream>
#include <vector>

// Unique 3-Digit Even Numbers

int totalNumbers(vector<int> &digits)
{
    // Step 1: Store the frequency of each digit from the input
    int digitCount[10] = {0};
    for (int digit : digits)
    {
        digitCount[digit]++;
    }

    int distinctEvenCount = 0;

    // Step 2: Check every valid 3-digit even number
    for (int i = 100; i <= 998; i += 2)
    {
        int currentNumberCount[10] = {0};
        int temp = i;

        // Extract each digit and increase its required count
        currentNumberCount[temp % 10]++;
        temp /= 10;
        currentNumberCount[temp % 10]++;
        temp /= 10;
        currentNumberCount[temp % 10]++;

        // Step 3: Verify if we have enough digits to form 'i'
        bool canForm = true;
        for (int j = 0; j < 10; ++j)
        {
            if (currentNumberCount[j] > digitCount[j])
            {
                canForm = false;
                break;
            }
        }

        // Step 4: Increment total if the number can be successfully formed
        if (canForm)
        {
            distinctEvenCount++;
        }
    }

    return distinctEvenCount;
}
