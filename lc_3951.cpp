#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long cost_per_second = (brightness + 2) / 3;

        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> merged;

        for (int i = 0; i < (int)intervals.size();) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            int j = i + 1;
            while (j < (int)intervals.size() && intervals[j][0] <= r) {
                r = max(intervals[j][1], r);
                j++;
            }

            merged.push_back({ l, r });
            i = j;
        }

        long long ans = 0;
        for (auto& [l, r] : merged) {
            long long time = r - l + 1;
            ans += time * cost_per_second;
        }

        return ans;
    }
};
