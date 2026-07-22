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
    int x, y, z;
    cin >> x >> y >> z;
    long long k;
    cin >> k;

    // x * y * z = k
    // z = k / (y * x)


    long long ans = 0;
    for (long long x1 = 1; x1 <= k && x1 <= x; ++x1) {
        for (long long y1 = 1; y1 <= k && y1 <= y; ++y1) {
            if (k % (y1 * x1) != 0) {
                continue;
            }

            long long z1 = k / (y1 * x1);
            if (z1 > z) {
                continue;
            }

            long long local = (x - x1 + 1) * (y - y1 + 1) * (z - z1 + 1);
            ans = max(ans, local);
        }
    }

    cout << ans << '\n';
}
