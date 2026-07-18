#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        // that dp thing with knapsacks? but the unbounded one?
        // unordered_map<string, int> => min cost to achieve string s??
        // 20 * 200 * 5000 * 200 is not feasible

        vector<int> cost = costs;
        for (int i = 0; i < rules.size(); ++i) {
            string s = rules[i][0];
            for (char c : s) {
                if (c == '*') cost[i]++;
            }
        }

        int n = target.size();
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
            if (target[i] == source[i]) {
                dp[i] = i - 1 >= 0 ? dp[i - 1] : 0;
            }

            for (int j = 0; j < rules.size(); ++j) {
                string p = rules[j][0];
                string r = rules[j][1];

                if (p.size() > (i + 1)) {
                    continue;
                }

                int start = i - (p.size() - 1);
                bool good = true;
                for (int k = 0; k < p.size(); ++k) {
                    if (r[k] != target[start + k]) {
                        good = false;
                        break;
                    }

                    if (!(p[k] == '*' || p[k] == source[start + k])) {
                        good = false;
                        break;
                    }
                }

                if (good) {
                    int prev = start - 1 >= 0 ? dp[start - 1] : 0;
                    if (prev != INT_MAX) {
                        dp[i] = min(dp[i], prev + cost[j]);
                    }
                }
            }
        }

        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};
