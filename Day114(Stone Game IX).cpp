#include <iostream>
#include <vector>

// Stone Game IX

bool stoneGameIX(vector<int> &stones)
{
    int cnt[3] = {0, 0, 0};

    // Count frequencies of remainders
    for (int stone : stones)
    {
        cnt[stone % 3]++;
    }

    // If the number of 0s is even, Alice wins if she has both 1s and 2s available.
    if (cnt[0] % 2 == 0)
    {
        return cnt[1] > 0 && cnt[2] > 0;
    }
    // If the number of 0s is odd, Alice needs a large imbalance to win.
    else
    {
        return std::abs(cnt[1] - cnt[2]) > 2;
    }
}
