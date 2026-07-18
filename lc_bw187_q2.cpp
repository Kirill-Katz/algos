#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // n even => seq[0] < seq[1]
        // n odd => seq[0] > seq[1] < seq[2]

        // n % 2 == 0 => s, s + m, s + m - 1, s + 2m - 1
        // n % 2 == 1 => s, s - 1, s + m - 1
        // n = 3, s = 4, m = 5
        // 4, 9, 8
        // 4 + 1 * 5 - 1 = 8
        // 7,

        if (n % 2 == 0) {
            long long ans = max(s * 1LL, s + (n * 1LL / 2) * m * 1LL - (n - 1) / 2);
            return ans;
        } else {
            long long ans = max(s * 1LL, s + (n * 1LL / 2) * m * 1LL - (n - 2) / 2);
            return ans;
        }
    }
};
