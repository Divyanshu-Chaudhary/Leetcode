#include <iostream>

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        // return (n&(n-1)) == 0;

        // if(n == 1){
        //     return true;
        // }
        // return n%2==0 && isPowerOfTwo(n/2);

        // if((int)pow(2, 30)%n==0){
        if ((1 << 30) % n == 0)
        {
            return true;
        }
        return false;
    }
};