#include <iostream>
#include <vector>

// Maximum Alternating Sum of Squares

long long maxAlternatingSum(vector<int> &nums)
{
    std::vector<long long> squares;
    squares.reserve(nums.size());

    // Square each number. Using long long to prevent overflow.
    for (int x : nums)
    {
        squares.push_back(1LL * x * x);
    }

    // Sort the squares in descending order
    std::sort(squares.begin(), squares.end(), std::greater<long long>());

    long long max_score = 0;
    int n = squares.size();
    int num_positive_terms = (n + 1) / 2; // Equivalent to ceil(n / 2.0)

    // Add the largest squares
    for (int i = 0; i < num_positive_terms; ++i)
    {
        max_score += squares[i];
    }

    // Subtract the remaining smaller squares
    for (int i = num_positive_terms; i < n; ++i)
    {
        max_score -= squares[i];
    }

    return max_score;
}
