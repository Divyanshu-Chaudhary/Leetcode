#include <iostream>
#include <vector>

// Stone Game VIII

int stoneGameVIII(vector<int> &stones)
{
    int n = stones.size();

    // 1. Calculate prefix sums in-place to save memory
    for (int i = 1; i < n; i++)
    {
        stones[i] += stones[i - 1];
    }

    // 2. Base case: The score if a player takes all stones up to the very last one
    int best = stones[n - 1];

    // 3. Iterate backward from the second-to-last valid choice down to index 1
    // (Index 0 is invalid because a player must take x > 1 stones)
    for (int i = n - 2; i >= 1; i--)
    {
        // best is the max between:
        // - Skipping (keeping the 'best' from i+1)
        // - Taking (getting the prefix sum here MINUS the opponent's 'best' from i+1)
        best = max(best, stones[i] - best);
    }

    return best; // Alice's best possible score difference
}
