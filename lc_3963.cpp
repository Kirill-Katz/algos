#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string> ans(m, string(n, '#'));

        for (int i = 0; i < n; ++i) {
            ans[0][i] = '.';
        }

        for (int j = 0; j < m; ++j) {
            ans[j][n - 1] = '.';
        }

        return ans;
    }
};
