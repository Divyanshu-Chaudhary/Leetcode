#include <iostream>

// Clear Digits

string clearDigits(string s)
{
    // int i = 0;
    // while(i<s.length()){
    //     if(isdigit(s[i])){
    //         s.erase(i, 1);
    //         if(i-1>=0){
    //             s.erase(i-1, 1);
    //             i--;
    //         }
    //     }
    //     else{
    //         i++;
    //     }
    // }
    // return s;
    string result = "";
    for (char &ch : s)
    {
        if (isdigit(ch))
        {
            if (!result.empty())
            {
                result.pop_back();
            }
        }
        else
        {
            result.push_back(ch);
        }
    }
    return result;
}
