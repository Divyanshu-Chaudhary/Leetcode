#include <iostream>
#include <vector>

// Intersection of Two Arrays II

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // unordered_map<int, int> mp;
    // for(int &num : nums1){
    //     mp[num]++;
    // }
    // vector<int> result;
    // for(int i=0; i<nums2.size(); i++){
    //     int num = nums2[i];
    //     if(mp[num]>0){
    //         mp[num]--;
    //         result.push_back(num);
    //     }
    // }
    // return result;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    vector<int> result;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
            j++;
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
    return result;
}
