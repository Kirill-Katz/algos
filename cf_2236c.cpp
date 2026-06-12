#include <algorithm>
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
    int a, b, x;
    cin >> a >> b >> x;

    int current = 0;
    int ans = abs(a - b);

    while (a != b) {
        if (a > b) {
            a /= x;
        } else {
            b /= x;
        }

        current++;
        ans = min(ans, abs(a - b) + current);
    }

    cout << ans << '\n';
}
