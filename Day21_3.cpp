#include <iostream>
#include <vector>

int buyChoco(vector<int> &prices, int money)
{
    int low = INT_MAX;
    int secondLow = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        if (low > prices[i])
        {
            secondLow = low;
            low = prices[i];
        }
        else
        {
            secondLow = min(secondLow, prices[i]);
        }
    }
    if ((money - (low + secondLow)) >= 0)
    {
        return money - (low + secondLow);
    }
    return money;
}

int main()
{
    return 0;
}