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

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = m;

    multiset<int> vals;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if ((int)vals.size() < m) {
                vals.insert(a[i][j]);
            } else if (*vals.begin() < a[i][j]) {
                vals.erase(vals.begin());
                vals.insert(a[i][j]);
            }
        }

        int local = 0;
        int cnt = 0;

        bool possible = false;
        for (auto it = vals.rbegin(); it != vals.rend(); ++it) {
            local += *it;
            ++cnt;

            if (local >= v[i]) {
                possible = true;
                break;
            }
        }

        if (possible) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
}
