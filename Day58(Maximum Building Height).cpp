#include <iostream>
#include <vector>

// Maximum Building Height

int maxBuilding(int n, vector<vector<int>> &restrictions)
{
    // 1. Add the implicit restriction for the first building
    restrictions.push_back({1, 0});

    // Sort restrictions by building ID
    sort(restrictions.begin(), restrictions.end());

    // Add a dummy restriction for the last building if it's not restricted
    if (restrictions.back()[0] != n)
    {
        restrictions.push_back({n, 1000000000});
    }

    int m = restrictions.size();

    // 2. Left-to-right pass to propagate height constraints forward
    for (int i = 1; i < m; ++i)
    {
        int dist = restrictions[i][0] - restrictions[i - 1][0];
        restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
    }

    // 3. Right-to-left pass to propagate height constraints backward
    for (int i = m - 2; i >= 0; --i)
    {
        int dist = restrictions[i + 1][0] - restrictions[i][0];
        restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
    }

    // 4. Find the maximum height between any two adjacent restricted buildings
    int maxHeight = 0;
    for (int i = 1; i < m; ++i)
    {
        int h1 = restrictions[i - 1][1];
        int h2 = restrictions[i][1];
        int dist = restrictions[i][0] - restrictions[i - 1][0];

        // The peak height between these two points
        int peak = (h1 + h2 + dist) / 2;
        maxHeight = max(maxHeight, peak);
    }

    return maxHeight;
}
