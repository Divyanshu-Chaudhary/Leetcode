#include <iostream>
#include <vector>

// Block Placement Queries

struct SegmentTree
{
    vector<int> tree;
    int n;

    SegmentTree(int n) : n(n), tree(4 * n + 1, 0) {}

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val)
    {
        update(1, 0, n, idx, val);
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return 0;
        if (l <= start && end <= r)
            return tree[node];

        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    int query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(1, 0, n, l, r);
    }
};

vector<bool> getResults(vector<vector<int>> &queries)
{
    // Find the maximum 'x' across all queries to size our segment tree
    int max_x = 0;
    for (const auto &q : queries)
    {
        max_x = max(max_x, q[1]);
    }

    SegmentTree st(max_x);
    set<int> obstacles;
    obstacles.insert(0); // Origin is our starting boundary

    vector<bool> results;

    for (const auto &q : queries)
    {
        if (q[0] == 1)
        { // Type 1: Add Obstacle
            int x = q[1];

            auto it = obstacles.upper_bound(x);
            int next_x = -1;
            if (it != obstacles.end())
            {
                next_x = *it;
            }
            int prev_x = *prev(it);

            // Set the gap for the newly inserted obstacle at x
            st.update(x, x - prev_x);

            // Update the gap for the next obstacle if it exists
            if (next_x != -1)
            {
                st.update(next_x, next_x - x);
            }

            obstacles.insert(x);
        }
        else
        { // Type 2: Check Block Placement
            int x = q[1];
            int sz = q[2];

            // Find the largest obstacle strictly <= x
            auto it = prev(obstacles.upper_bound(x));
            int prev_x = *it;

            // The largest gap between established obstacles strictly before prev_x
            int max_gap = st.query(0, prev_x);

            // The trailing gap from the last valid obstacle up to boundary x
            int last_gap = x - prev_x;

            // Check if either the established max gap or the trailing gap fits the block
            if (max(max_gap, last_gap) >= sz)
            {
                results.push_back(true);
            }
            else
            {
                results.push_back(false);
            }
        }
    }

    return results;
}
