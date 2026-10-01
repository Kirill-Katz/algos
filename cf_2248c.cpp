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
    int n;
    cin >> n;

    vector<int> a(2 * n);
    map<int,long long> m;

    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        m[a[i]] = i;
    }

    vector<long long> dp(2 * n, 0LL);

    for (long long i = 0; i < 2 * n; ++i) {
        // either leave dp[i] alone, or use dp[i - 1] and add the single value
        // if we are at dp[0] we can only add 1 to dp[0], so max(dp[0], 1LL)
        dp[i] = i == 0 ? max(dp[i], 1LL) : max(dp[i], dp[i - 1] + 1LL);

        if (m[a[i]] == i) { // we are on the right don't need to check the segment
            continue;
        }

        long long r = m[a[i]];
        long long prev = i == 0 ? 0LL : dp[i - 1];
        // either leave r alone or use the whole segment
        dp[r] = max(dp[r], prev + (r - i + 1LL) * (r - i + 1LL));
    }

    cout << dp[2 * n - 1] << '\n';
}
