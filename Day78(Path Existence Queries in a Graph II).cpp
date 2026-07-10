#include <iostream>
#include <vector>

// Path Existence Queries in a Graph II

vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    // S will store pairs of {value, original_index}
    vector<pair<int, int>> S(n);
    for (int i = 0; i < n; ++i)
    {
        S[i] = {nums[i], i};
    }

    // Sort the array by value to allow greedy rightward jumps
    sort(S.begin(), S.end());

    // Map from original index to the new index in the sorted array
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
    {
        pos[S[i].second] = i;
    }

    // 2^19 is ~5.24 * 10^5, which is safely larger than the max possible N (usually 10^5)
    int LOG = 20;
    vector<vector<int>> up(n, vector<int>(LOG));

    // Two pointers to compute the furthest reachable node in 1 step (up[i][0])
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        // Use 1LL to prevent integer overflow if nums[i] + maxDiff exceeds INT_MAX
        while (j + 1 < n && S[j + 1].first <= 1LL * S[i].first + maxDiff)
        {
            j++;
        }
        up[i][0] = j;
    }

    // Fill binary lifting table for 2^k steps
    for (int k = 1; k < LOG; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }

    vector<int> answer;
    answer.reserve(queries.size());

    for (const auto &q : queries)
    {
        int u = q[0];
        int v = q[1];

        if (u == v)
        {
            answer.push_back(0);
            continue;
        }

        int idx_u = pos[u];
        int idx_v = pos[v];

        // Undirected graph, so we always process left to right
        if (idx_u > idx_v)
        {
            swap(idx_u, idx_v);
        }

        // If even taking the maximum possible jumps doesn't reach idx_v, they are disconnected
        if (up[idx_u][LOG - 1] < idx_v)
        {
            answer.push_back(-1);
            continue;
        }

        int curr = idx_u;
        int steps = 0;

        // Greedily take large jumps as long as we haven't reached or surpassed idx_v
        for (int k = LOG - 1; k >= 0; --k)
        {
            if (up[curr][k] < idx_v)
            {
                curr = up[curr][k];
                steps += (1 << k);
            }
        }

        // `curr` is now the closest we can get to `idx_v` without reaching it.
        // One final step will bridge the gap.
        answer.push_back(steps + 1);
    }

    return answer;
}
