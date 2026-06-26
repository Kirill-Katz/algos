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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<bool> is_broken(n * m + 1, false);
    vector<bool> have(n * m + 1, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            have[a[i][j]] = true;

            if (i - 1 >= 0 && a[i][j] == a[i - 1][j]) {
                is_broken[a[i][j]] = true;
            }

            if (i + 1 < n && a[i][j] == a[i + 1][j]) {
                is_broken[a[i][j]] = true;
            }

            if (j + 1 < m && a[i][j] == a[i][j + 1]) {
                is_broken[a[i][j]] = true;
            }

            if (j - 1 < m && a[i][j] == a[i][j - 1]) {
                is_broken[a[i][j]] = true;
            }
        }
    }

    int ans = 0;
    bool have_base = false;

    for (int v = 1; v <= m * n; ++v) {
        if (have[v]) {
            if (is_broken[v] && !have_base) {
                have_base = true;
            } else if (is_broken[v]) {
                ans += 2;
            } else {
                ans++;
            }
        }
    }

    cout << ans - (!have_base) << '\n';
}
