#include <iostream>
#include <vector>

// Maximum Ice Cream Bars

int maxIceCream(vector<int> &costs, int coins)
{
    sort(begin(costs), end(costs));

    int count = 0;

    for (int &cost : costs)
    {
        if (cost > coins)
            return count;
        else
        {
            count++;
            coins -= cost;
        }
    }

    return count;
}
