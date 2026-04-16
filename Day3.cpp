#include <iostream>
using namespace std;

bool judgeCircle(string moves)
{
    int x = 0, y = 0;
    for (char c : moves)
    {
        if (c == 'U')
        {
            y++;
        }
        else if (c == 'R')
        {
            x++;
        }
        else if (c == 'D')
        {
            y--;
        }
        else if (c == 'L')
        {
            x--;
        }
    }
    if (x == 0 && y == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}