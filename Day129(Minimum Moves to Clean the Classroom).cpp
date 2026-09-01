#include <iostream>
#include <vector>

// Minimum Moves to Clean the Classroom

int minMoves(vector<string> &classroom, int energy)
{
    int m = classroom.size();
    int n = classroom[0].size();
    int start_r = -1, start_c = -1;
    vector<pair<int, int>> litters;

    // 1. Locate the starting position and all litter coordinates
    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (classroom[r][c] == 'S')
            {
                start_r = r;
                start_c = c;
            }
            else if (classroom[r][c] == 'L')
            {
                litters.push_back({r, c});
            }
        }
    }

    int K = litters.size();
    int target_mask = (1 << K) - 1; // All bits set to 1 for K litters

    // If there is no litter to collect, we are already done
    if (K == 0)
        return 0;

    // Map the grid coordinates to a specific litter index for quick lookup
    vector<vector<int>> litter_idx(m, vector<int>(n, -1));
    for (int i = 0; i < K; ++i)
    {
        litter_idx[litters[i].first][litters[i].second] = i;
    }

    // BFS Queue stores tuples: {row, col, collected_litter_mask, current_energy}
    queue<tuple<int, int, int, int>> q;
    q.push({start_r, start_c, 0, energy});

    // Visited array to store the MAXIMUM energy we've had at a specific state (r, c, mask)
    // Initialized to -1
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(1 << K, -1)));
    visited[start_r][start_c][0] = energy;

    int steps = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // 2. Perform BFS to find the shortest path
    while (!q.empty())
    {
        int sz = q.size();

        // Process layer by layer to keep track of minimum steps easily
        while (sz--)
        {
            auto [r, c, mask, e] = q.front();
            q.pop();

            // If all litters have been collected, return the step count
            if (mask == target_mask)
            {
                return steps;
            }

            // If out of energy, we cannot make any adjacent moves
            if (e == 0)
                continue;

            // Explore all 4 adjacent directions
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundaries and obstacles
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X')
                {
                    int next_e = e - 1;
                    int next_mask = mask;

                    // Apply reset if stepping on an 'R' cell
                    if (classroom[nr][nc] == 'R')
                    {
                        next_e = energy;
                    }
                    // Update bitmask if stepping on an uncollected 'L' cell
                    else if (classroom[nr][nc] == 'L')
                    {
                        int idx = litter_idx[nr][nc];
                        if (idx != -1)
                        {
                            next_mask |= (1 << idx);
                        }
                    }

                    // We only queue this next state if it leaves us with STRICTLY MORE energy
                    // than any previous visit to this exact (cell + litter mask) combination
                    if (next_e > visited[nr][nc][next_mask])
                    {
                        visited[nr][nc][next_mask] = next_e;
                        q.push({nr, nc, next_mask, next_e});
                    }
                }
            }
        }
        steps++;
    }

    // Path is blocked or max capacity is structurally insufficient
    return -1;
}
