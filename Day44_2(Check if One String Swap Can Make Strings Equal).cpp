#include <iostream>

// Check if One String Swap Can Make Strings Equal

bool areAlmostEqual(string s1, string s2)
{
    int n = s1.length();
    if (s1 == s2)
    {
        return true;
    }
    int diff = 0;
    // int freq1[26]={0};
    // int freq2[26]={0};
    // for(int i=0; i<n; i++){
    //     if(s1[i]!=s2[i]){
    //         diff++;
    //     }
    //     if(diff>2){
    //         return false;
    //     }
    //     freq1[s1[i]-'a']++;
    //     freq2[s2[i]-'a']++;
    // }
    // for(int i=0; i<26; i++){
    //     if(freq1[i]!=freq2[i]){
    //         return false;
    //     }
    // }
    // return true;
    int firstIdx = 0;
    int secondIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            diff++;
            if (diff > 2)
            {
                return false;
            }
            else if (diff == 1)
            {
                firstIdx = i;
            }
            else
            {
                secondIdx = i;
            }
        }
    }
    return s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx];
}
