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
    string a;
    string b;
    cin >> a >> b;

    vector<int> pref_a(a.size() + 1, 0);
    vector<int> pref_b(b.size() + 1, 0);

    pref_a[0] = 0;
    pref_b[0] = 0;

    for (int i = 1; i <= (int)a.size(); ++i) {
        pref_a[i] = (pref_a[i - 1] + (a[i - 1] - '0')) % 10;
    }

    for (int i = 1; i <= (int)b.size(); ++i) {
        pref_b[i] = (pref_b[i - 1] + (b[i - 1] - '0')) % 10;
    }

    if (pref_a.back() != pref_b.back()) {
        cout << -1 << '\n';
        return;
    }

    // (pref_a[r] - pref_a[l]) % 10 == (pref_b[i] - pref_b[j]) % 10
    // =>
    // (pref_a[r] - pref_b[i]) % 10 == (pref_b[l] - pref_a[j]) % 10

    int n = (int)a.size();
    int m = (int)b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {

            if (pref_a[i] == pref_b[j]) {
                if (i == 0 || j == 0) {
                    continue;
                }

                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                int prev_i = i == 0 ? 0 : dp[i - 1][j];
                int prev_j = j == 0 ? 0 : dp[i][j - 1];

                dp[i][j] = max(prev_i, prev_j);
            }
        }
    }

    cout << dp[n][m] << '\n';
}
