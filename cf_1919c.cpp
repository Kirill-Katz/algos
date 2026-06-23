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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 5 2 1 4
    int mx = INT_MAX;
    int mn = INT_MAX;

    int ans = 0;

    for (int v : a) {
        if (mn > mx) {
            swap(mn, mx);
        }

        if (v <= mn) {
            mn = v;
        } else if (v <= mx) {
            mx = v;
        } else {
            ans++;
            mn = v;
        }
    }

    cout << ans << '\n';
}
