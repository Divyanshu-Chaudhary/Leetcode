#include <iostream>
#include <stack>

int maxDepth(string s)
{
    // int maxi=0;
    // int n=s.length();
    // stack<char> stk;
    // for(char &ch : s){
    //     if(ch=='('){
    //         stk.push(ch);
    //     }
    //     else if(ch==')'){
    //         stk.pop();
    //     }
    //     maxi = max(maxi, (int)stk.size());
    // }
    // return maxi;

    int openBrackets = 0;
    int result = 0;
    for (char &ch : s)
    {
        if (ch == '(')
        {
            openBrackets++;
        }
        else if (ch == ')')
        {
            openBrackets--;
        }
        result = max(result, openBrackets);
    }
    return result;
}