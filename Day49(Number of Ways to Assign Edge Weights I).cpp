#include <iostream>
#include <vector>

// Number of Ways to Assign Edge Weights I

static const int MOD = 1e9 + 7;

long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int assignEdgeWeights(vector<vector<int>> &edges)
{
    int n = (int)edges.size() + 1;
    vector<vector<int>> adj(n + 1);

    for (auto &e : edges)
    {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<int> vis(n + 1, 0);

    q.push({1, 0});
    vis[1] = 1;

    int maxDepth = 0;

    while (!q.empty())
    {
        auto [node, depth] = q.front();
        q.pop();

        maxDepth = max(maxDepth, depth);

        for (int nxt : adj[node])
        {
            if (!vis[nxt])
            {
                vis[nxt] = 1;
                q.push({nxt, depth + 1});
            }
        }
    }

    if (maxDepth == 0)
        return 0;
    return (int)power(2, maxDepth - 1);
}
