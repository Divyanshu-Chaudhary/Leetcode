#include <iostream>
#include <vector>

// Minimum Cost to Acquire Required Items

long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
{
    long long option1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

    long long option2 = 1LL * min(need1, need2) * costBoth;

    if (need1 > need2)
    {
        option2 += 1LL * (need1 - need2) * cost1;
    }
    else
    {
        option2 += 1LL * (need2 - need1) * cost2;
    }

    long long option3 = 1LL * max(need1, need2) * costBoth;

    return min({option1, option2, option3});
}
