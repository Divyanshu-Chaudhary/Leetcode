#include <iostream>
#include <vector>

// Count Commas in Range

int countCommas(int n)
{
    return n < 1000 ? 0 : n - 999;
}
