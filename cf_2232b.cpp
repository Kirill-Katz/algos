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

    long long min_val = a[0];
    vector<long long> ans(n);
    ans[0] = a[0];
    long long sum = a[0];

    for (int i = 1; i < n; ++i) {
        sum += a[i];
        ans[i] = min(min_val, sum / (i + 1));
        min_val = min(min_val, ans[i]);
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
