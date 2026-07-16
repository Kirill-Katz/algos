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
    int n, x, y;
    cin >> n >> x >> y;

    // 11111 => x = n and y = 1
    // -1-1-1-1-1 => x = 1 and y = n
    // 1-1-1-11 => x = 2 and y = n - 1
    // 1 1 -1 1 1 => x =

    // -1 1 -1 1 -1

    vector<int> a(n, 1);

    int val = -1;
    for (int i = y - 2; i >= 0; --i) {
        a[i] = val;
        val = -val;
    }

    val = -1;
    for (int i = x; i < n; ++i) {
        a[i] = val;
        val = -val;
    }

    for (int v : a) {
        cout << v << ' ';
    }
    cout << '\n';
}
