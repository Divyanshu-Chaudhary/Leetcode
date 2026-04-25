#include <iostream>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t)
{
    unordered_map<char, int> mp;
    for (char ch : s)
    {
        mp[ch]++;
    }
    for (char ch : t)
    {
        mp[ch]--;
        if (mp[ch] < 0)
        {
            return ch;
        }
    }
    return 'X';
}

int main()
{
    return 0;
}