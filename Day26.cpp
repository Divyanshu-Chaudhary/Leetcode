#include <iostream>
#include <vector>
#include <unordered_set>

bool binarySearch(vector<int> &nums, int num)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == num)
        {
            return true;
        }
        else if (nums[mid] < num)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    // unordered_set<int> st(begin(nums1), end(nums1));
    // for(int &num : nums2){
    //     if(st.find(num)!=st.end()){
    //         return num;
    //     }
    // }
    // return -1;


    // for(int &num : nums1){
    //     if(binarySearch(nums2, num)){
    //         return num;
    //     }
    // }
    // return -1;

    int m = nums1.size();
    int n = nums2.size();

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] == nums2[j])
        {
            return nums1[i];
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return -1;
}