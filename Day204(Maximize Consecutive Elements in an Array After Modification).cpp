#include <iostream>
#include <vector>
#include <unordered_map>

// Maximize Consecutive Elements in an Array After Modification

int maxSelectedElements(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> dp;
    dp.reserve(nums.size() * 2);
    int ans = 0;

    for (int x : nums)
    {
        int len_x = dp.count(x) ? dp[x] : 0;
        int len_prev = dp.count(x - 1) ? dp[x - 1] : 0;

        dp[x + 1] = len_x + 1;
        dp[x] = len_prev + 1;

        ans = max({ans, dp[x], dp[x + 1]});
    }

    return ans;
}
