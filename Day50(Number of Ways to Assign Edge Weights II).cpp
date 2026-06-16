#include <iostream>
#include <vector>

// Number of Ways to Assign Edge Weights II

static const int MOD = 1e9 + 7;
int LOG;
vector<vector<int>> up;
vector<int> depth;
vector<vector<int>> adj;
vector<long long> pow2;

void bfs(int root, int n)
{
    queue<int> q;
    q.push(root);
    vector<int> visited(n + 1, 0);
    visited[root] = 1;
    up[0][root] = 0;
    depth[root] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                q.push(v);
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++)
    {
        if (diff & (1 << j))
            a = up[j][a];
    }

    if (a == b)
        return a;

    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[j][a] != up[j][b])
        {
            a = up[j][a];
            b = up[j][b];
        }
    }

    return up[0][a];
}

vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
{
    int n = (int)edges.size() + 1;

    adj.assign(n + 1, {});
    for (auto &e : edges)
    {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LOG = 1;
    while ((1 << LOG) <= n)
        LOG++;

    up.assign(LOG, vector<int>(n + 1, 0));
    depth.assign(n + 1, 0);

    bfs(1, n);

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    pow2.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &q : queries)
    {
        int u = q[0], v = q[1];
        int p = lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[p];

        if (dist == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back((int)pow2[dist - 1]);
        }
    }

    return ans;
}
