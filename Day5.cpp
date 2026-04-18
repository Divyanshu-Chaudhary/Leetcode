#include <iostream>
using namespace std;

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    return rev;
}

int mirrorDistance(int n)
{

    int rev = reverse(n);

    return abs(n - rev);
}

int main()
{
    return 0;
}