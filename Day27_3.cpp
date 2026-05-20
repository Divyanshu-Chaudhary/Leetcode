#include <iostream>
#include <vector>

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            t += min(tickets[i], tickets[k]);
        }
        else
        {
            t += min(tickets[k] - 1, tickets[i]);
        }
    }
    return t;
}
