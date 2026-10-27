#include <iostream>
#include <vector>
#include <string>

// Create Grid With Exactly One Path

vector<string> createGrid(int m, int n)
{
    // Initialize the grid entirely with obstacles
    vector<string> grid(m, string(n, '#'));

    // Carve out a single path along the top row
    for (int j = 0; j < n; ++j)
    {
        grid[0][j] = '.';
    }

    // Continue the path down the rightmost column
    for (int i = 1; i < m; ++i)
    {
        grid[i][n - 1] = '.';
    }

    return grid;
}
