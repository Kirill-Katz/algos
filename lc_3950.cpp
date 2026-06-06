#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int prev = n & 1;
        n >>= 1;

        int cnt = 0;
        while (n > 0) {
            if ((n & 1) == prev) {
                cnt += (n & 1);
            }

            prev = n & 1;
            n >>= 1;
        }

        return cnt == 1;
    }
};

// 1100
