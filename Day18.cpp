#include <iostream>
#include <vector>

int numSpecial(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> rowArr(m, 0);
    vector<int> colArr(n, 0);
    int result = 0;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (mat[row][col] == 1)
            {
                rowArr[row]++;
                colArr[col]++;
            }
        }
    }
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (mat[row][col] == 0)
            {
                continue;
            }
            if (rowArr[row] == 1 && colArr[col] == 1)
            {
                result++;
            }
        }
    }
    
    return result;
}

int main()
{
    return 0;
}