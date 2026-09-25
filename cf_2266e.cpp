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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> spf(n + 1);
    for (int p = 2; p <= n; ++p) {
        if (spf[p] != 0) {
            continue;
        }

        for (int j = 0; j * p <= n; ++j) {
            if (spf[j * p] == 0) {
                spf[j * p] = p;
            }
        }
    }

    vector<long long> dp(n + 1);

    for (long long v = k + 1; v <= n; ++v) {
        long long min_v = LLONG_MAX;

        long long tmp = v;
        while (tmp > 1) {
            long long p = 1LL * spf[tmp];
            min_v = min(min_v, p * dp[v / p]);
            tmp = tmp / p;
        }

        dp[v] = 1 + min_v;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[a[i]];
    }

    cout << ans << '\n';
}
