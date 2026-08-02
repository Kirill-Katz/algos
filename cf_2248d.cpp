#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    string t;

    cin >> s;
    cin >> t;

    vector<int> pref_diff(n + 1);
    vector<int> pref_same(n + 1);
    pref_diff[0] = 0;
    pref_same[0] = 0;

    for (int i = 1; i <= n; ++i) {
        pref_same[i] = pref_same[i-1] + (s[i-1] == t[i-1]);
        pref_diff[i] = pref_diff[i-1] + (s[i-1] != t[i-1]) * (s[i-1] == '0' ? -1 : 1);
    }

    for (int i = 0; i < q; ++i) {
        int r, l;
        cin >> l >> r;

        int diff_cnt = pref_diff[r] - pref_diff[l-1];
        int same_cnt = pref_same[r] - pref_same[l-1];

        if (abs(diff_cnt) <= same_cnt) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    // 0 1, 0 1, 1 1 => 00111
    // so 0 1 pairs with 1 0
    // 0 0 pairs with 1 1
    //
    // the only problematic unpaired digits are of the form 0 1 and 1 0
    //
    // so either we have everyone paired, i.e we get 0011 (even string length)
    // or we have a problematic unpaired position AND we have either an unpaired 1 1 or 0 0
    // otherwise "NO"
}
