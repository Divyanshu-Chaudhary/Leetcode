#include <iostream>
#include <vector>

vector<int> separateDigits(vector<int> &nums)
{
    vector<int> ans;

    for (int num : nums)
    {
        vector<int> temp;

        // extract digits
        while (num > 0)
        {
            temp.push_back(num % 10);
            num /= 10;
        }

        // reverse order to maintain original digit order
        reverse(temp.begin(), temp.end());

        // add into answer
        for (int digit : temp)
        {
            ans.push_back(digit);
        }
    }

    return ans;
}

int main()
{
    return 0;
}