#include <iostream>
#include <vector>

// Path Existence Queries in a Graph I

vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    // Array to store the component ID for each node
    vector<int> component(n);
    int current_component = 0;

    // Node 0 is always in component 0
    component[0] = current_component;

    // Group nodes into components based on maxDiff
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] - nums[i - 1] > maxDiff)
        {
            current_component++;
        }
        component[i] = current_component;
    }

    // Answer each query
    vector<bool> result;
    result.reserve(queries.size());
    for (const auto &query : queries)
    {
        result.push_back(component[query[0]] == component[query[1]]);
    }

    return result;
}
