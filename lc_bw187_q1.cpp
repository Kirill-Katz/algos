#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int x_cnt = 0;
        int y_cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
           if (s[i] == x) x_cnt++;
           if (s[i] == y) y_cnt++;
        }

        string ans;
        for (int i = 0; i < y_cnt; ++i) ans.push_back(y);
        for (int i = 0; i < x_cnt; ++i) ans.push_back(x);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != x && s[i] != y ) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
