#include <iostream>

string reversePrefix(string word, char ch)
{
    // int j = word.find(ch);
    // int i = 0;
    // while(i<j){
    //     swap(word[i], word[j]);
    //     i++;
    //     j--;
    // }
    // return word;

    reverse(word.begin(), word.begin() + word.find(ch) + 1);
    return word;
}
