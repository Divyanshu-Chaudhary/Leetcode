#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
{
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    vector<vector<char>> result(n, vector<char>(m));

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = boxGrid[j][i];
        }
    }
    // Reverse
    for (vector<char> &row : result)
    {
        reverse(begin(row), end(row));
    }

    // Gravity
    for (int j = 0; j < m; j++)
    {
        int bottomSpace = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (result[i][j] == '*')
            {
                bottomSpace = i - 1;
                continue;
            }
            if (result[i][j] == '#')
            {
                result[i][j] = '.';
                result[bottomSpace][j] = '#';
                bottomSpace--;
            }
        }
    }

    return result;
}

int main()
{
    return 0;
}