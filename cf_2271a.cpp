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
    int a, b;
    cin >> a >> b;

    if (a < 0 || abs(b) > a + 1) {
        cout << -1 << '\n';
        return;
    }

    if (a % 2 == b % 2) {
        cout << a << '\n';
    } else {
        cout << a + 1 << '\n';
    }
}
