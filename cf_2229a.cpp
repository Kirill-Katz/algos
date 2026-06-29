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

    int min_v = INT_MAX;
    int max_v = INT_MIN;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min_v = min(min_v, a[i]);
        max_v = max(max_v, a[i]);
    }

    int avg = (min_v + max_v) / 2;

    cout << max(avg - min_v, max_v - avg) << '\n';
}
