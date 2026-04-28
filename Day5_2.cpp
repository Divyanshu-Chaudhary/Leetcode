#include <iostream>
using namespace std;

int numberOfMatches(int n)
{
    int result = 0;
    int i = n;
    while (i > 1)
    {
        if (i % 2 == 0)
        {
            result = result + (i / 2);
            i = i / 2;
        }
        else
        {
            result = result + (i / 2);
            i = (i / 2) + 1;
        }
    }
    return result;
}

int main()
{
    return 0;
}