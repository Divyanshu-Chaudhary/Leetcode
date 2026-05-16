#include <iostream>
#include <vector>

int maxLengthBetweenEqualCharacters(string s)
{
    int n = s.length();
    int result = -1;
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(s[i]==s[j]){
    //             result = max(result, j-i-1);
    //         }
    //     }
    // }
    // return result;
    // unordered_map<char, int>mp;
    // for(int i=0; i<n; i++){
    //     char ch = s[i];
    //     if(mp.find(ch)==mp.end()){
    //         mp[ch] = i;
    //     }
    //     else{
    //         result = max(result, i-mp[ch]-1);
    //     }
    // }
    // return result;
    vector<int> count(26, -1);
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (count[ch - 'a'] == -1)
        {
            count[ch - 'a'] = i;
        }
        else
        {
            result = max(result, i - count[ch - 'a'] - 1);
        }
    }
    return result;
}