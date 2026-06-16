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
    long long n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;

    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }

    cout << min(n - abs(x2 - x1), abs(x2 - x1)) + k << '\n';
}
