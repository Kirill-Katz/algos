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
    int n, k;
    cin >> n >> k;

    // max possible k is ((n + 1) / 2 - 1) + (n / 2 - 1)

    if (k > ((n + 1) / 2 - 1) + (n / 2 - 1)) {
        cout << -1 << '\n';
        return;
    }

    int need_ones = k / 2 + 1;
    int need_zeros = (k + 1) / 2 + 1;

    for (int i = 0; i < need_ones; ++i) {
        cout << '1';
    }

    for (int i = 0; i < need_zeros; ++i) {
        cout << '0';
    }

    bool flag = true;
    for (int i = 0; i < (n - need_ones - need_zeros); ++i) {
        cout << (flag ? '1' : '0');
        flag = !flag;
    }

    cout << '\n';
}
