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
    int x0, y0, R;
    cin >> x0 >> y0 >> R;

    // sqrt((x0 - x)^2 + (y0 - y)^2) = R
    //
    // x^2 - 2xx0 + x0^2 + y0^2 - 2y0y + y^2 = R^2
    //

    int x = x0 - R;
    int y = y0;

    cout << x << ' ' << y << '\n';
}
