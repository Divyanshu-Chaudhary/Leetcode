#include <iostream>
#include <vector>

// Maximum Number of Items From Sale II

int maximumSaleItems(vector<vector<int>> &items, int budget)
{
    int maxFactor = 0;
    long long minPrice = LLONG_MAX;

    for (const auto &item : items)
    {
        maxFactor = max(maxFactor, item[0]);
        minPrice = min(minPrice, (long long)item[1]);
    }

    // Count frequency of each factor
    vector<int> freq(maxFactor + 1, 0);
    for (const auto &item : items)
    {
        freq[item[0]]++;
    }

    // multiples[f] = number of other items j whose factor is divisible by f
    vector<int> multiples(maxFactor + 1, 0);
    for (int f = 1; f <= maxFactor; ++f)
    {
        if (freq[f] == 0)
            continue;
        int count = 0;
        for (int m = f; m <= maxFactor; m += f)
        {
            count += freq[m];
        }
        multiples[f] = count - 1; // exclude item i itself (i != j)
    }

    // Sort items by price ascending
    sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    long long remBudget = budget;
    long long ans = 0;

    for (const auto &item : items)
    {
        long long factor = item[0];
        long long price = item[1];

        // Bonus purchase is only worth it if price <= 2 * minPrice
        if (price > 2 * minPrice)
            break;

        long long canBuy = min((long long)multiples[factor], remBudget / price);
        ans += 2 * canBuy;
        remBudget -= canBuy * price;
    }

    // Spend remaining budget on the cheapest item (1 item per copy)
    ans += remBudget / minPrice;

    return (int)ans;
}