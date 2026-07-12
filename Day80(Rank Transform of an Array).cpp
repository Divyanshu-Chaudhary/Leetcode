#include <iostream>
#include <vector>
#include <unordered_map>

// Rank Transform of an Array

vector<int> arrayRankTransform(vector<int> &arr)
{
    // 1. Create a copy of the array and sort it
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    // 2. Map each unique element to its rank
    unordered_map<int, int> rank_map;
    int current_rank = 1;

    for (int num : sorted_arr)
    {
        // Only assign a rank if we haven't seen this number before
        if (rank_map.find(num) == rank_map.end())
        {
            rank_map[num] = current_rank;
            current_rank++;
        }
    }

    // 3. Replace elements in the original array with their ranks
    vector<int> result(arr.size());
    for (int i = 0; i < arr.size(); ++i)
    {
        result[i] = rank_map[arr[i]];
    }

    return result;
}
