#include <iostream>
#include <vector>

bool isGood(vector<int> &nums)
{
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }
    vector<int> res(maxi, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        res[nums[i] - 1]++;
    }
    if (res[maxi - 1] != 2)
    {
        return false;
    }
    for (int i = 0; i < maxi - 1; i++)
    {
        if (res[i] == 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}