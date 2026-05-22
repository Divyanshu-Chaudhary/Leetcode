#include <iostream>
#include <vector>

int findMaxK(vector<int> &nums)
{
    // sort(begin(nums), end(nums));
    // int result = -1;
    // int i=0, j=nums.size()-1;
    // while(i<j){
    //     if(-nums[i]==nums[j]){
    //         return nums[j];
    //     }
    //     if(nums[i]<nums[j]){
    //         j--;
    //     }
    //     else{
    //         i--;
    //     }
    // }
    // return result;

    int arr[2001] = {0};
    int result = -1;
    for (int &num : nums)
    {
        if (arr[-num + 1000] == 1)
        {
            result = max(result, abs(num));
        }
        arr[num + 1000] = 1;
    }
    return result;
}
