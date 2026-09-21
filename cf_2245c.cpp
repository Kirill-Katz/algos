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
    int n, k; cin >> n >> k; if (n == 1) {
        if (k == 1) {
            cout << "YES\n0\n";
        } else {
            cout << "NO\n";
        } return; } int b = n ^ k; vector<int> ans; if (b == 0) { cout << "YES\n"; for (int i = 1; i < n; ++i) { ans.push_back(i); } ans.push_back(0); } else if (b < n) { cout << "YES\n"; for (int i = 1; i < n; ++i) { if (i != b) { ans.push_back(i); } } ans.push_back(0); ans.push_back(b); } else { int hb_b = 31 - __builtin_clz(b); int hb_n = 31 - __builtin_clz(n - 1); if (hb_b != hb_n) { cout << "NO\n"; return; } int c = (n - 1) ^ b; cout << "YES\n"; for (int i = 1; i < n - 1; ++i) { if (i != c) { ans.push_back(i); } } ans.push_back(0); ans.push_back(c);
        ans.push_back(n - 1);
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
