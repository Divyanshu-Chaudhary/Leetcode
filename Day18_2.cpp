#include <iostream>
#include <vcector>
#include <unordered_map>

// Unordeerd Map -> Hash Map
string destCity(vector<vector<string>> &paths)
{
    unordered_map<string, int> mp;
    for (auto &path : paths)
    {
        string source = path[0];
        mp[source] = 1;
    }
    for (auto &path : paths)
    {
        string dest = path[1];
        if (mp[dest] != 1)
        {
            return dest;
        }
    }
    return "";
}
// Hash Set
string destCity(vector<vector<string>> &paths)
{
    unordered_set<string> st;
    for (auto &path : paths)
    {
        string source = path[0];
        st.insert(source);
    }
    for (auto &path : paths)
    {
        string dest = path[1];
        if (st.find(dest) == st.end())
        {
            return dest;
        }
    }
    return "";
}

int main()
{
    return 0;
}