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


constexpr long long mod = 998'244'353;

long long pow_(long long a, long long b) {
    a %= mod;

    long long temp = a;
    long long ans = 1;
    while (b > 0) {
        if (b&1) {
            ans = temp * ans % mod;
        }

        temp = temp * temp % mod;
        b>>=1;
    }

    return ans;
}
void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the largest element is always the root
    //
    // assume a[] is sorted in ascending order.
    // The we can choose the parent of a[0] to be one of the n - 1 values,
    // for a[1] we have n - 2 values and so on.

    ranges::sort(a);

    vector<long long> suf(n);
    suf[n - 1] = 0LL;

    for (int i = n - 2; i >= 0; --i) {
        suf[i] = (suf[i + 1] + a[i + 1]) % mod;
    }

    long long ans = 0;

    long long total_configs = 1;
    for (int i = 2; i <= n - 1; ++i) {
        total_configs = (total_configs * i) % mod;
    }

    for (int i = 0; i < n - 1; ++i) {
        long long mult = n - 1 - i;

        long long base = (suf[i] - (a[i] * mult) % mod + mod) % mod;

        ans = (ans + (base * (total_configs * pow_(mult, mod - 2))) % mod) % mod;
    }

    cout << ans << '\n';
}
