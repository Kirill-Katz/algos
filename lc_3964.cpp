#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<pair<int,int>> seg;

        for (int i = 0; i < n; ++i) {
            if (lights[i] > 0) {
                seg.push_back({ max(0, i - lights[i]), min(n - 1, i + lights[i]) });
            }
        }

        sort(seg.begin(), seg.end());

        vector<pair<int,int>> merged;
        for (auto& [l, r] : seg) {
            if (merged.empty() || l > merged.back().second) {
                merged.push_back({l, r});
            } else {
                merged.back().second = max(merged.back().second, r);
            }
        }

        int ans = 0;
        int cur = 0;

        for (auto& [l, r] : merged) {
            ans += (l - cur + 2) / 3;
            cur = r + 1;
        }

        ans += (max(0, (n - 1) - cur + 1) + 2) / 3;

        return ans;
    }
};
