#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(i);
    }
    vector<int> result;

    for (int q : queries)
    {
        int element = nums[q];
        vector<int> &vec = mp[element];
        int sz = vec.size();

        if (sz == 1)
        {
            result.push_back(-1);
            continue;
        }
        int pos = lower_bound(begin(vec), end(vec), q) - begin(vec);
        int res = INT_MAX;

        int right = vec[(pos + 1) % sz];
        int d = abs(q - right);
        int circularDist = n - d;
        res = min({res, d, circularDist});

        int left = vec[(pos - 1 + sz) % sz];
        d = abs(q - left);
        circularDist = n - d;
        res = min({res, d, circularDist});

        result.push_back(res);
    }

    return result;
}

int main()
{
    return 0;
}