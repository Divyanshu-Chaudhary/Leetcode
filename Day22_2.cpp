#include <iosteram>
#include <unordered_set>

bool isPathCrossing(string path)
{
    unordered_set<string> st;
    int x = 0;
    int y = 0;
    string key = to_string(x) + "_" + to_string(y);
    st.insert(key);
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == 'E')
        {
            x++;
        }
        if (path[i] == 'W')
        {
            x--;
        }
        if (path[i] == 'N')
        {
            y++;
        }
        if (path[i] == 'S')
        {
            y--;
        }
        key = to_string(x) + "_" + to_string(y);
        if (st.find(key) != st.end())
        {
            return true;
        }
        st.insert(key);
    }
    return false;
}