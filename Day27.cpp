#include <iostream>
#include <vector>

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> result(n);
    // for(int i=0; i<n; i++){
    //     int count = 0;
    //     for(int x=0; x<=i; x++){
    //         for(int y=0; y<=i; y++){
    //             if(B[y]==A[x]){
    //                 count++;
    //                 break;
    //             }
    //         }
    //     }
    //     result[i] = count;
    // }

    int count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
        if (mp[A[i]] == 2)
        {
            count++;
        }
        mp[B[i]]++;
        if (mp[B[i]] == 2)
        {
            count++;
        }
        result[i] = count;
    }

    return result;
}
