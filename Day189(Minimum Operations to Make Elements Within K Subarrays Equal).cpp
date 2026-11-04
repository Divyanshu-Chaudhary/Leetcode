#include <iostream>
#include <vector>

// Minimum Operations to Make Elements Within K Subarrays Equal

long long minOperations(vector<int> &nums, int x, int k)
{
    int n = nums.size();

    // Two multisets to maintain the median of each window.
    multiset<int> left, right;

    long long sumL = 0, sumR = 0;

    // Keep left.size() == right.size()
    // or left.size() == right.size() + 1.
    auto rebalance = [&]()
    {
        while (left.size() > right.size() + 1)
        {
            auto it = prev(left.end());
            int val = *it;

            left.erase(it);
            sumL -= val;

            right.insert(val);
            sumR += val;
        }

        while (left.size() < right.size())
        {
            auto it = right.begin();
            int val = *it;

            right.erase(it);
            sumR -= val;

            left.insert(val);
            sumL += val;
        }
    };

    // Insert an element into the window.
    auto addNum = [&](int val)
    {
        if (left.empty() || val <= *left.rbegin())
        {
            left.insert(val);
            sumL += val;
        }
        else
        {
            right.insert(val);
            sumR += val;
        }

        rebalance();
    };

    // Remove one occurrence of an element.
    auto removeNum = [&](int val)
    {
        auto it = left.find(val);

        if (it != left.end())
        {
            left.erase(it);
            sumL -= val;
        }
        else
        {
            it = right.find(val);
            right.erase(it);
            sumR -= val;
        }

        rebalance();
    };

    // Calculate minimum cost for every window of size x.
    vector<long long> cost;
    cost.reserve(n - x + 1);

    for (int i = 0; i < n; i++)
    {
        addNum(nums[i]);

        if (i >= x)
        {
            removeNum(nums[i - x]);
        }

        if (i >= x - 1)
        {
            long long median = *left.rbegin();

            long long operations =
                median * (long long)left.size() - sumL + sumR - median * (long long)right.size();

            cost.push_back(operations);
        }
    }

    // DP:
    // dp[t][i] = minimum operations to select
    // exactly t non-overlapping windows
    // from the first i elements.

    const long long INF = LLONG_MAX / 4;

    vector<vector<long long>> dp(
        k + 1, vector<long long>(n + 1, INF));

    // Zero windows require zero operations.
    fill(dp[0].begin(), dp[0].end(), 0LL);

    for (int t = 1; t <= k; t++)
    {
        for (int i = 1; i <= n; i++)
        {

            // Option 1: Skip the current position.
            dp[t][i] = dp[t][i - 1];

            // Option 2: Take a window ending at i - 1.
            if (i >= x && dp[t - 1][i - x] != INF)
            {
                dp[t][i] = min(
                    dp[t][i],
                    dp[t - 1][i - x] + cost[i - x]);
            }
        }
    }

    return dp[k][n];
}
