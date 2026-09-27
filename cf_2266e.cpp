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
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> spf(n + 1, 0);

    for (long long p = 2; p <= n; ++p) {
        if (spf[p] != 0) continue;

        for (long long i = 1; p * i <= n; ++i) {
            if (spf[p * i] != 0) continue;
            spf[p * i] = p;
        }
    }

    vector<long long> dp(n + 1, 0);

    for (long long v = k + 1; v <= n; ++v) {
        long long min_v = LLONG_MAX;
        long long tmp = v;

        while (tmp > 1) {
            long long p = spf[tmp];
            min_v = min(min_v, 1 + p * dp[v / p]);
            tmp /= p;
        }

        dp[v] = min_v;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[a[i]];
    }

    cout << ans << '\n';
}
