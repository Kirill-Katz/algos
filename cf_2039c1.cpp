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
    long long x, m;
    cin >> x >> m;

    long long ans = 0;
    long long f = 63 - __builtin_clzll(x);

    for (long long y = 1; y <= min((1LL << (f + 1)) - 1LL, m); ++y) {
        long long res = x ^ y;
        if (res == 0) continue;
        if (x % res == 0 || y % res == 0) {
            ans++;
        }
    }

    cout << ans << '\n';
}
