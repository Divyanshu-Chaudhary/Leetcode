#include<iostream>
#include<vector>
#include <climits>

using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
        int a=INT_MAX;
        for(int i=0; i<nums.size() && a>abs(i-start); i++){
            if(nums[i]==target){
                a=min(a,abs(i-start));
            }
        }
        return a;
    }


int main()
{
    return 0;
}