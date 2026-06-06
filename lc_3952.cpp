#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<pair<int,int>> blocks;

        vector<long long> prefix(n+1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        // prefix[r + 1] - prefix[l] is the subarray [l, r] sum

        long long ans = 0;
        int i = 0;
        while (i < n && s[i] == '1') i++;
        ans += prefix[i] - prefix[0];

        for (int j = i; j < n; ++j) {
            if (s[j] == '0') continue;

            int k = j;
            while (k < n && s[k] == '1') {
                k++;
            }

            blocks.push_back({ j, k });
            j = k;
        }

        for (auto& [l, r] : blocks) {
            long long min_v = INT_MAX;
            long long subarr_sum = 0;
            for (int i = l - 1; i < r; ++i) {
                min_v = min(min_v, 1LL * nums[i]);
                subarr_sum += nums[i];
            }
            ans += (subarr_sum - min_v);
        }

        return ans;
    }
};
