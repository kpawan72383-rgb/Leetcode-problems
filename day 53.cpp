#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        long long remBudget = budget;
        long long minPrice = LLONG_MAX;
        int maxFactor = 0;

        for (const auto& item : items) {
            minPrice = min(minPrice, static_cast<long long>(item[1]));
            maxFactor = max(maxFactor, item[0]);
        }

        // freq[x] = number of items with factor == x
        vector<long long> freq(maxFactor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        // multiplesCount[d] = number of items with factor a multiple of d (including d itself)
        vector<long long> multiplesCount(maxFactor + 1, 0);
        for (int d = 1; d <= maxFactor; ++d) {
            if (freq[d] == 0) continue;
            for (int m = d; m <= maxFactor; m += d) {
                multiplesCount[d] += freq[m];
            }
        }

        // Each entry: {price, number of free items gained by buying up to this many copies}
        vector<pair<long long, long long>> boosts;
        boosts.reserve(n);

        for (const auto& item : items) {
            int f = item[0];
            long long price = item[1];
            long long gain = multiplesCount[f] - 1; // exclude self
            if (gain > 0 && price <= 2 * minPrice) {
                boosts.push_back({price, gain});
            }
        }

        sort(boosts.begin(), boosts.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        long long totalItems = 0;
        for (const auto& [price, gain] : boosts) {
            if (remBudget < price) break;
            long long take = min(gain, remBudget / price);
            totalItems += 2 * take;
            remBudget -= take * price;
        }

        totalItems += remBudget / minPrice;
        return static_cast<int>(totalItems);
    }
};
