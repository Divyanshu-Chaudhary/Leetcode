#include <iostream>
#include <vector>

// Number of Paths with Max Score

vector<int> pathsWithMaxScore(vector<string> &board)
{
    int n = board.size();
    long long MOD = 1e9 + 7;

    // max_score[i][j] stores the maximum score to reach cell (i, j)
    vector<vector<long long>> max_score(n, vector<long long>(n, -1));
    // paths[i][j] stores the number of ways to achieve max_score[i][j]
    vector<vector<long long>> paths(n, vector<long long>(n, 0));

    // Base case: Starting position at bottom-right
    max_score[n - 1][n - 1] = 0;
    paths[n - 1][n - 1] = 1;

    // Directions: Up, Left, Up-Left
    int dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};

    // Traverse the board from bottom-right to top-left
    for (int r = n - 1; r >= 0; --r)
    {
        for (int c = n - 1; c >= 0; --c)
        {
            // Skip if the current cell is unreachable
            if (paths[r][c] == 0)
                continue;

            // Push states to the 3 possible next moves
            for (auto &d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                // Check bounds and obstacle ('X')
                if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X')
                {
                    long long val = 0;
                    if (board[nr][nc] != 'E' && board[nr][nc] != 'S')
                    {
                        val = board[nr][nc] - '0';
                    }

                    long long current_score = max_score[r][c] + val;

                    // Found a strictly greater score path
                    if (current_score > max_score[nr][nc])
                    {
                        max_score[nr][nc] = current_score;
                        paths[nr][nc] = paths[r][c];
                    }
                    // Found an alternative path with the same max score
                    else if (current_score == max_score[nr][nc])
                    {
                        paths[nr][nc] = (paths[nr][nc] + paths[r][c]) % MOD;
                    }
                }
            }
        }
    }

    // If the end destination 'E' (0,0) is unreachable, return [0, 0]
    if (max_score[0][0] == -1)
    {
        return {0, 0};
    }

    return {(int)max_score[0][0], (int)paths[0][0]};
}
