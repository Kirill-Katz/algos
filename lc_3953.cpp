#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int n = (int)nums.size();

        vector<int> cnt(1e5 + 1);
        set<int> nums_set;

        for (int i = 0; i < n; ++i) {
           int num = nums[i];
           nums_set.insert(num);

            for (int d = 1; d * d <= num; ++d) {
                if (num % d == 0) {
                    cnt[d]++;

                    if (d != num / d) {
                        cnt[num / d]++;
                    }
                }
            }
        }

        auto compute = [&](int val) {
            vector<int> prime_factors;
            int v = val;

            if (v % 2 == 0) {
                prime_factors.push_back(2);
                while (v % 2 == 0) {
                    v /= 2;
                }
            }

            for (int p = 3; p * p <= v; p += 2) {
                if (v % p == 0) {
                    prime_factors.push_back(p);
                    while (v % p == 0) {
                        v /= p;
                    }
                }
            }

            if (v > 1) {
                prime_factors.push_back(v);
            }

            int bad = 0;

            for (int bit = 1; bit < (1 << (int)prime_factors.size()); ++bit) {
                int local = 1;
                for (int i = 0; i < (int)prime_factors.size(); ++i) {
                    if ((bit >> i) & 1) {
                        local *= prime_factors[i];
                    }
                }

                if (__builtin_popcount(bit) % 2 == 1) {
                    bad += cnt[local];
                } else {
                    bad -= cnt[local] ;
                }
            }

            if (nums_set.contains(val)) {
                bad = max(0, bad - 1);
            } else {
                bad = max(1, bad);
            }

            return val - bad;
        };

        int ans = maxVal - n;
        for (int val = maxVal; val >= 1; --val) {
            ans = max(ans, compute(val));
        }

        for (int i = 0; i < n; ++i) {
            if (nums_set.contains(nums[i])) {
                ans = max(ans, compute(nums[i]));
            }
        }

        return ans;
    }
};
