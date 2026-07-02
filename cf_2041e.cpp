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

    solve();

    return 0;
}

void solve() {
    int a, b;
    cin >> a >> b;

    // (b + x + y) / 3 = a
    // b + x + y = 3a
    // y = 3 * a - x - b
    //
    // x <= a <= y
    //

    for (int x = -1e3; x < a; ++x) {
        int y = 3*a - x - b;

        if (y > a) {
            cout << 3 << '\n';
            cout << x << ' ' <<  b << ' ' << y << '\n';
            return;
        }
    }
}
