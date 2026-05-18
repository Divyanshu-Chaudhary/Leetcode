#include <iostream>

string maximumOddBinaryNumber(string s)
{
    int n = s.length();
    string result = string(n, '0');

    // int i = 0;
    // for(char &ch : s){
    //     if(ch=='1'){
    //         if(result[n-1]=='1'){
    //             result[i]='1';
    //             i++;
    //         }
    //         else{
    //             result[n-1]='1';
    //         }
    //     }
    // }
    int one = count(s.begin(), s.end(), '1');
    int j = 0;

    while (one > 1)
    {
        result[j] = '1';
        j++;
        one--;
    }
    result[n - 1] = '1';

    return result;
}