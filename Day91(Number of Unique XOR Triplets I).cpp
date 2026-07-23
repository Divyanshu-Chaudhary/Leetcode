#include <iostream>
#include <vector>

// Number of Unique XOR Triplets I

int uniqueXorTriplets(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1 || n == 2)
        return n;

    int ans = 1; // 2^0;
    while (ans <= n)
    {
        ans = (ans << 1);
    }

    return ans;
}
