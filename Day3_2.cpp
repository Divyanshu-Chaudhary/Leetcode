#include <iostream>
using namespace std;

int n, m;

bool dfs(int x, int y, int px, int py, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    vis[x][y] = 1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == grid[x][y])
        {

            if (!vis[nx][ny])
            {
                if (dfs(nx, ny, x, y, grid, vis))
                    return true;
            }
            else if (!(nx == px && ny == py))
            {
                // visited and not parent -> cycle
                return true;
            }
        }
    }

    return false;
}
bool containsCycle(vector<vector<char>> &grid)
{
    n = grid.size();
    m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (dfs(i, j, -1, -1, grid, vis))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}