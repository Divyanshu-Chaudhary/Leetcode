#include <iostream>
#include <vector>

// Find Center of Star Graph

int findCenter(vector<vector<int>> &edges)
{
    // unordered_map<int, int> degrees;
    // for(auto &vec : edges){
    //     int u = vec[0];
    //     int v = vec[1];
    //     degrees[u]++;
    //     degrees[v]++;
    // }
    // for(auto &it : degrees){
    //     if(it.second == edges.size()){
    //         return it.first;
    //     }
    // }
    // return -1;

    vector<int> first = edges[0];
    vector<int> second = edges[1];
    if (first[0] == second[0] || first[0] == second[1])
    {
        return first[0];
    }
    return first[1];
}
