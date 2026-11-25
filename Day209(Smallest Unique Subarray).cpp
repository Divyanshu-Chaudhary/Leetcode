#include <iostream>
#include <vector>
#include <unordered_map>

// Smallest Unique Subarray

struct State
{
    int len = 0;
    int link = -1;
    unordered_map<int, int> next;
};

int smallestUniqueSubarray(vector<int> &nums)
{
    int n = nums.size();
    vector<State> st;
    st.reserve(2 * n);
    st.push_back(State()); // root = 0

    vector<int> cnt;
    cnt.reserve(2 * n);
    cnt.push_back(0);

    int last = 0;

    // 1. Build the Suffix Automaton
    for (int x : nums)
    {
        int cur = st.size();
        st.push_back({st[last].len + 1, -1, {}});
        cnt.push_back(1); // Non-cloned state represents a prefix ending here

        int p = last;
        while (p != -1 && !st[p].next.count(x))
        {
            st[p].next[x] = cur;
            p = st[p].link;
        }

        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[x];
            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {
                int clone = st.size();
                st.push_back({st[p].len + 1, st[q].link, st[q].next});
                cnt.push_back(0); // Cloned states start with 0 count

                while (p != -1 && st[p].next[x] == q)
                {
                    st[p].next[x] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    // 2. Bucket sort states by length (topological order)
    vector<int> bucket(n + 1, 0);
    for (const auto &s : st)
        bucket[s.len]++;
    for (int i = 1; i <= n; ++i)
        bucket[i] += bucket[i - 1];

    vector<int> order(st.size());
    for (int i = st.size() - 1; i >= 0; --i)
    {
        order[--bucket[st[i].len]] = i;
    }

    // 3. Propagate occurrence counts in reverse topological order
    for (int i = st.size() - 1; i > 0; --i)
    {
        int u = order[i];
        if (st[u].link != -1)
        {
            cnt[st[u].link] += cnt[u];
        }
    }

    // 4. Find the shortest unique subarray
    int ans = n;
    for (int u = 1; u < st.size(); ++u)
    {
        if (cnt[u] == 1)
        {
            ans = min(ans, st[st[u].link].len + 1);
        }
    }

    return ans;
}
