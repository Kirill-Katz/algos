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

constexpr long long mod = 998244353;
void solve() {
    long long n, x;
    cin >> n >> x;

    // ok so for some set of numbers to have their xor = 0 we
    // have to have each bit either set to 1 or 0, or we have to have the same amount of numbers
    // with bit i set to 1 and 0.
    //
    // i % 4 == 0 => pref[i] = i
    // i % 4 == 1 => pref[i] = 1
    // i % 4 == 2 => pref[i] = i + 1
    // i % 4 == 3 => pref[i] = 0
    //
    // for r:
    // 4*k + 1 >= x and 4*k + 1 <= n;
    // k >= (x - 1) / 4 and k <= (n - 1) / 4
    // (x - 1 + 3) / 4 <= k <= (n - 1) / 4
    //
    // for l:
    // 4 * k + 1 <= x - 1 and 4 * k + 1 >= 0;
    // k <= (x - 2) / 4 and k >= -1 / 4 <=> k >= 0

    long long left_1 = (x + 2) / 4;
    long long right_1 = (n + 3) / 4 - (x + 2) / 4;

    long long left_0 = x / 4 + 1;
    long long right_0 = (n + 1) / 4 - x / 4;

    long long ans = ((__int128)left_0 * right_0 % mod + (__int128)left_1 * right_1 % mod) % mod;
    cout << ans % 998224353 << '\n';
}
