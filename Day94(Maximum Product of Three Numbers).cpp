#include <iostream>
#include <vector>

// Maximum Product of Three Numbers

int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    // Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());

    // Calculate the two possible maximum products
    int product1 = nums[0] * nums[1] * nums[2];
    int product2 = nums[0] * nums[n - 1] * nums[n - 2];

    // Return the maximum of the two
    return max(product1, product2);
}
