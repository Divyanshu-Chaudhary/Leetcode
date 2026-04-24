#include <iostream>
using namespace std;

int furthestDistanceFromOrigin(string moves)
{
    int R = 0, L = 0, U = 0;
    for (char ch : moves)
    {
        if (ch == 'R')
        {
            R++;
        }
        else if (ch == 'L')
        {
            L++;
        }
        else
        {
            U++;
        }
    }
    return abs(R - L) + U;
}

int main()
{
    return 0;
}