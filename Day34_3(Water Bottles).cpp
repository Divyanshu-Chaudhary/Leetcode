#include <iostream>

// Water Bottles

int numWaterBottles(int numBottles, int numExchange)
{
    int sum = numBottles;
    while (numBottles >= numExchange)
    {
        int n = numBottles / numExchange;
        numBottles = numBottles % numExchange;
        sum += n;
        numBottles += n;
    }
    return sum;
}
