#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        constexpr long long mod = 1e9 + 7;

        int n = nums.size();
        // number of inversions?

        vector<int> suffix_a(n + 1, 0); // less than to a
        vector<int> suffix_b(n + 1, 0); // less than or equal to b

        for (int i = n - 1; i >= 0; --i) {
            suffix_a[i] = suffix_a[i + 1] + (nums[i] < a);
            suffix_b[i] = suffix_b[i + 1] + (nums[i] <= b);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > b) {
                ans = (ans + suffix_b[i + 1]) % mod;
            } else if (nums[i] >= a) {
                ans = (ans + suffix_a[i + 1]) % mod;
            }
        }

        return ans;
    }
};
