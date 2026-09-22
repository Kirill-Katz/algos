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
    int easy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        easy += a[i] == 0;
    }

    if (easy < 2) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;

    ans += a[0] != 0;
    ans += a[n - 1] != 0;

    cout << ans << '\n';
}
