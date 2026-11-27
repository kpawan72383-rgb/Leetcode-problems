#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; ++i) {
            int f_i = items[i][0];
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % f_i == 0) {
                    ++freeCount[i];
                }
            }
        }

        const int NEG_INF = -1e9;
        // dp[b] = max items obtainable with exact or up-to budget b
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int firstGain = 1 + freeCount[i];

            // Phase 1 (0/1): Buy first copy of item i (triggers freebies)
            // Phase 2 (unbounded): Buy additional copies of item i (+1 each)
            vector<int> nextDp = dp;

            for (int b = price; b <= budget; ++b) {
                // First copy of item i starting from state without item i's bonus
                nextDp[b] = max(nextDp[b], dp[b - price] + firstGain);
            }
            for (int b = price; b <= budget; ++b) {
                // Extra copy of item i after having at least one copy
                if (nextDp[b - price] > 0) {
                    nextDp[b] = max(nextDp[b], nextDp[b - price] + 1);
                }
            }

            dp.swap(nextDp);
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};
