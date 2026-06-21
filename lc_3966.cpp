#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long goodIntegers(long long l, long long r, int k) {
        auto count = [&](long long r) {
            long long temp = r;
            vector<int> ds;

            while (temp > 0) {
                ds.push_back(temp % 10);
                temp /= 10;
            };
            reverse(ds.begin(), ds.end());

            int d_cnt = ds.size();
            vector<vector<long long>> dp(d_cnt + 1, vector<long long>(15, 0));

            for (int d = 0; d <= 9; d++) {
                dp[0][d] = 1;
            }

            for (int p = 1; p < d_cnt; ++p) {
                for (int prev = 0; prev <= 9; ++prev) {
                    for (int cur = max(0, prev - k); cur <= min(9, prev + k); ++cur) {
                        dp[p][cur] += dp[p - 1][prev];
                    }
                }
            }

            long long ans = 0;

            for (int p = 0; p < d_cnt - 1; ++p) {
                for (int d = 1; d <= 9; ++d) {
                    ans += dp[p][d];
                }
            }

            int prev = -1;
            for (int i = 0; i < d_cnt; ++i) {
                int lim = ds[i];
                int rem = d_cnt - i - 1;

                for (int d = (i == 0 ? 1 : 0); d < lim; ++d) {
                    if (prev == -1 || abs(prev - d) <= k) {
                        ans += dp[rem][d];
                    }
                }

                if (prev != -1 && abs(prev - lim) > k) {
                    return ans;
                }

                prev = lim;
            }

            return ans + 1;
        };

        return count(r) - count(l - 1);
    }
};
