#include <iostream>
#include <vector>

// Distinct Subsequences II

int distinctSubseqII(string s)
{
    int mod = 1e9 + 7;

    // Array to store the number of distinct subsequences ending with each character
    vector<int> endsWith(26, 0);

    // Running total of all distinct subsequences
    int total = 0;

    for (char c : s)
    {
        int old_val = endsWith[c - 'a'];

        // New subsequences ending with c is total + 1 (for the character itself)
        int new_val = (total + 1) % mod;

        // Update the endsWith array
        endsWith[c - 'a'] = new_val;

        // Update total: total = total - old_val + new_val
        // We add 'mod' before modulo to handle negative numbers in C++
        total = ((total - old_val) % mod + mod) % mod;
        total = (total + new_val) % mod;
    }

    return total;
}
