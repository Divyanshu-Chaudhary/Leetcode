#include <iostream>

// Number Complement

int findComplement(int num)
{
    int numbits = (int)(log2(num)) + 1;
    unsigned int mask = (1U << numbits) - 1;
    return num ^ mask;
}
