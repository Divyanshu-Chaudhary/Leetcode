#include <iostream>
#include <vector>

// Shortest Path With At Most K Consecutive Identical Characters

int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
{
    // Build directed adjacency list
    vector<vector<pair<int, int>>> adj(n);

    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
    }

    // dist[node][cnt] = minimum cost to reach node
    // with cnt consecutive occurrences of its label
    const long long INF = LLONG_MAX / 4;

    vector<vector<long long>> dist(
        n, vector<long long>(k + 1, INF));

    // {distance, node, consecutive count}
    using T = tuple<long long, int, int>;

    priority_queue<T, vector<T>, greater<T>> pq;

    // Starting at node 0, its label appears once
    dist[0][1] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty())
    {

        auto [d, u, cnt] = pq.top();
        pq.pop();

        // Ignore outdated states
        if (d != dist[u][cnt])
        {
            continue;
        }

        // First destination state popped is optimal
        if (u == n - 1)
        {
            return static_cast<int>(d);
        }

        // Explore outgoing edges
        for (auto &[v, w] : adj[u])
        {

            int nextCnt;

            if (labels[u] == labels[v])
            {
                nextCnt = cnt + 1;
            }
            else
            {
                nextCnt = 1;
            }

            // Reject invalid consecutive sequences
            if (nextCnt > k)
            {
                continue;
            }

            long long newDist = d + w;

            if (newDist < dist[v][nextCnt])
            {

                dist[v][nextCnt] = newDist;

                pq.push({newDist,
                         v,
                         nextCnt});
            }
        }
    }

    return -1;
}
