#include <iostream>
#include <vector>

// Lucky Numbers in a Matrix

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int rMax = INT_MIN;
    for (int row = 0; row < m; row++)
    {
        int rMin = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            rMin = min(rMin, matrix[row][col]);
        }
        rMax = max(rMax, rMin);
    }
    int cMin = INT_MAX;
    for (int col = 0; col < n; col++)
    {
        int cMax INT_MIN;
        for (int row = 0; row < m; row++)
        {
            cMax = max(cMax, matrix[row][col]);
        }
        cMin = min(cMin, cMax);
    }
    if (rMax == cMin)
    {
        return {rMax};
    }
    return {};
}
