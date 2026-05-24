#include <iostream>

// Longest Palindrome

int longestPalindrome(string s)
{
    int n = s.length();
    // int result = 0;

    // unordered_set<char> st;
    // for(char &ch : s){
    //     if(st.count(ch)){
    //         result+=2;
    //         st.erase(ch);
    //     }
    //     else{
    //         st.insert(ch);
    //     }
    // }
    // if(!st.empty()){
    //     result++;
    // }

    unordered_map<char, int> mp;
    // bool oddFreq = false;

    // for(char &ch : s){
    //     mp[ch]++;
    // }
    // for(auto &it : mp){
    //     if(it.second%2==0){
    //         result += it.second;
    //     }
    //     else{
    //         result += it.second-1;
    //         oddFreq = true;
    //     }
    // }

    // return result;

    int oddFreq = 0;
    for (char &ch : s)
    {
        mp[ch]++;
        if (mp[ch] % 2 != 0)
        {
            oddFreq++;
        }
        else
        {
            oddFreq--;
        }
    }

    if (oddFreq > 0)
    {
        return n - oddFreq + 1;
    }

    return n;
}
