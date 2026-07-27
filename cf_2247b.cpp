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
    int n, k, m;
    cin >> n >> k >> m;

    if (k > m) {
        cout << "NO" << '\n';
        return;
    }

    vector<long long> ans(n);

    cout << "YES" << '\n';
    ans[0] = m - k + 1;

    for (int i = 1; i < k; ++i) {
        ans[i] = 1;
    }
    for (int i = k; i < n; ++i) {
        ans[i] = 1;
    }
    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
