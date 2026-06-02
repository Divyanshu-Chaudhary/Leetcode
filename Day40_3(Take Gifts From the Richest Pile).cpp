#include <iostream>
#include <vector>

// Take Gifts From the Richest Pile

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> pq(begin(gifts), end(gifts)); // O(n)
    long long sum = 0;
    for (int &gift : gifts)
    {
        sum += gift;
    }
    long long mySum = 0;
    while (k--)
    {
        int maxEl = pq.top();
        pq.pop();
        int rem = sqrt(maxEl);
        mySum += maxEl - rem;
        pq.push(rem);
    }
    return sum - mySum;
}
