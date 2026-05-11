#include <iostream>

// O(nlogn) time, O(1) space
bool isAnagram(string s, string t)
{
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    return s == t;
}
// O(n) time, O(1) space
bool isAnagram1(string s, string t)
{
    vector<int> count(26, 0);
    for (char &ch : s)
    {
        count[ch - 'a']++;
    }
    for (char &ch : t)
    {
        count[ch - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}