#include <iostream>

// Minimum Recolors to Get K Consecutive Black Blocks

int minimumRecolors(string blocks, int k)
{
    int n = blocks.size();
    int i = 0;
    int j = 0;
    int ops = k;
    int w = 0;
    while (j < n)
    {
        if (blocks[j] == 'W')
        {
            w++;
        }
        if (j - i + 1 == k)
        {
            ops = min(ops, w);
            if (blocks[i] == 'W')
            {
                w--;
            }
            i++;
        }
        j++;
    }
    return ops;
}
