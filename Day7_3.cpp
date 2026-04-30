#include <iostream>
#include <vector>

using namespace std;

int m, n;

int solve(vector<vector<int>> &grid, int k, int i, int j, int cost, vector<vector<vector<int>>> &t)
{
    if (i >= m || j >= n)
    {
        return INT_MIN;
    }
    int newCost = cost + (grid[i][j] > 0);
    if (newCost > k)
    {
        return INT_MIN;
    }
    if (i == m - 1 && j == n - 1)
    {
        return grid[i][j];
    }
    if (t[i][j][cost] != -1)
    {
        return t[i][j][cost];
    }
    int down = solve(grid, k, i + 1, j, newCost, t);
    int right = solve(grid, k, i, j + 1, newCost, t);

    int best = max(down, right);
    if (best == INT_MIN)
    {
        return t[i][j][cost] = INT_MIN;
    }

    return t[i][j][cost] = grid[i][j] + best;
}

int maxPathScore(vector<vector<int>> &grid, int k)
{
    m = grid.size();
    n = grid[0].size();

    vector<vector<vector<int>>> t(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));

    int result = solve(grid, k, 0, 0, 0, t);

    return result == INT_MIN ? -1 : result;
}

int main()
{
    return 0;
}