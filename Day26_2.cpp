#include <isotream>
#include <vector>
#include <unordered_set>

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    // unordered_set<int> st1(begin(nums1), end(nums1));
    // vector<int> result;
    // for(int &num: nums2){
    //     if(st1.find(num)!=st1.end()){
    //         result.push_back(num);
    //         st1.erase(num);
    //     }
    // }
    // return result;

    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    vector<int> result;
    int i = 0, j = 0;
    int m = nums1.size();
    int n = nums2.size();
    while (i < m && j < n)
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            while (i < m - 1 && nums1[i] == nums1[i + 1])
            {
                i++;
            }
            while (j < n - 1 && nums2[j] == nums2[j + 1])
            {
                j++;
            }
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