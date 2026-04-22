#include <iostream>
#include <vector>
using namespace std;

vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
{
    vector<string> result;
    for (string &query : queries)
    {
        for (string &dic : dictionary)
        {
            int diff = 0;
            for (int i = 0; i < query.length(); i++)
            {
                if (query[i] != dic[i])
                {
                    diff++;
                }
                if (diff > 2)
                {
                    break;
                }
            }
            if (diff <= 2)
            {
                result.push_back(query);
                break;
            }
        }
    }
    return result;
}

int main()
{
    return 0;
}