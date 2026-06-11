#include <iostream>
#include <vector>

// Divide Array Into Equal Pairs

bool divideArray(vector<int> &nums)
{
    // unordered_map<int, int> mp;
    // for(int &x : nums){
    //     mp[x]++;
    // }
    // for(auto &it : mp){
    //     if(it.second%2!=0){
    //         return false;
    //     }
    // }
    // return true;

    // unordered_set<int> st;
    // for(int &x : nums){
    //     if(st.count(x)){
    //         st.erase(x);
    //     }
    //     else{
    //         st.insert(x);
    //     }
    // }
    // return st.empty();

    sort(begin(nums), end(nums));
    for (int i = 1; i < nums.size(); i += 2)
    {
        if (nums[i] != nums[i - 1])
        {
            return false;
        }
    }
    return true;
}
