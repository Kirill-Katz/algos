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
    int x, y;
    cin >> x >> y;
    int s = x + y;

    int x_p = 0;

    for (int i = 30; i >= 0; --i) {
        if ((s & (1 << i)) && x_p + (1 << i) <= x) {
            x_p += 1 << i;
        }
    }

    cout << s << ' ' << x - x_p << '\n';
}
