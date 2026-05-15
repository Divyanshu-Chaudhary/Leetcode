#include <iosteram>
#include <vector>

int findMin(vector<int> &nums)
{
    int r = nums.size() - 1;
    int l = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return nums[l];
}