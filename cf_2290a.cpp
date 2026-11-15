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
    array<int, 3> v;
    cin >> v[0] >> v[1] >> v[2];

    ranges::sort(v);

    if (v[2] - v[1] == v[1] - v[0] && v[1] - v[0] == 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
