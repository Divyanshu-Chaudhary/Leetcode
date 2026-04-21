#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int> &colors)
{

    int n = colors.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (colors[i] != colors[0])
        {
            result = max(result, i);
        }
        if (colors[i] != colors[n - 1])
        {
            result = max(result, abs(n - 1 - i));
        }
    }
    return result;
}

int main()
{
    return 0;
}