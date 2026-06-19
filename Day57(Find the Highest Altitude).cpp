#include <iostream>

// Find the Highest Altitude

int largestAltitude(vector<int> &gain)
{
    int output = 0;
    int maxi = output;
    for (int i = 0; i < gain.size(); i++)
    {
        output += gain[i];
        maxi = max(maxi, output);
    }
    return maxi;
}
