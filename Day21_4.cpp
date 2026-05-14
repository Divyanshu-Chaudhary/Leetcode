#include <iostream>
#include <vector>

int maxScore(string s)
{
    // int n = s.length();
    // int result = INT_MIN;
    // for(int i=0; i<=n-2; i++){
    //     int zero_count=0;
    //     for(int j=0; j<=i; j++){
    //         if(s[j] == '0'){
    //             zero_count++;
    //         }
    //     }
    //     int one_count=0;
    //     for(int j=i+1; j<n; j++){
    //         if(s[j] == '1'){
    //             one_count++;
    //         }
    //     }
    //     result = max(result, zero_count+one_count);
    // }
    // return result;

    int n = s.length();
    int score = INT_MIN;
    int zeroes = 0;
    int ones = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        if (s[i] == '1')
        {
            ones++;
        }
        else
        {
            zeroes++;
        }
        score = max(score, zeroes - ones);
    }
    if (s[n - 1] == '1')
    {
        ones++;
    }
    return score + ones;
}

int main()
{
    return 0;
}