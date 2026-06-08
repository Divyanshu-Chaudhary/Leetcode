#include <iostream>
#include <vector>

// Partition Array According to Given Pivot

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    int n = nums.size();
    vector<int> result(n);

    // vector<int> less;
    // vector<int> equal;
    // vector<int> great;
    // for(int i=0; i<n; i++){
    //     if(nums[i]<pivot){
    //         less.push_back(nums[i]);
    //     }
    //     else if(nums[i]==pivot){
    //         equal.push_back(nums[i]);
    //     }
    //     else{
    //         great.push_back(nums[i]);
    //     }
    // }
    // for(int &num : less){
    //     result.push_back(num);
    // }
    // for(int &num : equal){
    //     result.push_back(num);
    // }
    // for(int &num : great){
    //     result.push_back(num);
    // }

    int countLess = 0;
    int countEqual = 0;
    for (int &num : nums)
    {
        if (num < pivot)
        {
            countLess++;
        }
        else if (num == pivot)
        {
            countEqual++;
        }
    }
    int i = 0;
    int j = countLess;
    int k = countLess + countEqual;
    for (int &num : nums)
    {
        if (num < pivot)
        {
            result[i] = num;
            i++;
        }
        else if (num == pivot)
        {
            result[j] = num;
            j++;
        }
        else
        {
            result[k] = num;
            k++;
        }
    }

    return result;
}
