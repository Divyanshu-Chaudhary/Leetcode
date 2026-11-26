#include <iostream>

// Stone Removal Game

bool canAliceWin(int n)
{
    int take = 10;
    int steps = 0;

    while (n >= take)
    {
        n -= take;
        take--;
        steps++;
    }

    return steps % 2 == 1;
}
