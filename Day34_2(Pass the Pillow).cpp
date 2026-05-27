#include <iostream>
#include <vector>

// Pass the Pillow

int passThePillow(int n, int time)
{
    // int idx = 1;
    // int dir = 1;
    // while(time>0){
    //     if(idx+dir>=1 && idx+dir<=n){
    //         idx+=dir;
    //         time--;
    //     }
    //     else{
    //         dir*=-1;
    //     }
    // }
    // return idx;

    int rounds = time / (n - 1);
    int left = time % (n - 1);
    if (rounds % 2 == 0)
    {
        return left + 1;
    }
    else
    {
        return n - left;
    }
    return -1;
}
