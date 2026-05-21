#include <iostream>

int t[38];

int solve(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (t[n] != -1)
    {
        return t[n];
    }
    int a = solve(n - 1);
    int b = solve(n - 2);
    int c = solve(n - 3);
    return t[n] = a + b + c;
}

int tribonacci(int n)
{
    // memset(t, -1, sizeof(t));
    // return solve(n);

    // t[0]=0;
    // t[1]=1;
    // t[2]=1;
    // for(int i=3; i<38; i++){
    //     t[i]=t[i-1]+t[i-2]+t[i-3];
    // }
    // return t[n];

    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int a = 0;
    int b = 1;
    int c = 1;
    int d = a + b + c;
    for (int i = 3; i <= n; i++)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}

