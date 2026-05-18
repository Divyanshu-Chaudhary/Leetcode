#include <iostream>
#include <vector>

vector<int> sortedSquares(vector<int> &nums)
{
    // for(int i=0; i<nums.size(); i++){
    //     nums[i] = nums[i]*nums[i];
    // }
    // sort(begin(nums), end(nums));
    // return nums;

    int n = nums.size();
    vector<int> result(n);
    int i = 0, j = n - 1;
    int k = n - 1;
    while (k >= 0)
    {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];
        if (a > b)
        {
            result[k] = a;
            i++;
        }
        else
        {
            result[k] = b;
            j--;
        }
        k--;
    }
    return result;
}