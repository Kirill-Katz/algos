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

    if (k < n || k >= 2*n) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> ans(n, vector<int>(n));
    ans[0][0] = 1;

    int first_row = k - n;

    int v = 2;
    int r = 1;
    while (r <= first_row) {
        ans[0][r] = v;
        v++;
        r++;
    }

    int c = 1;
    while (r <= n - 1) {
        ans[c][r] = v;
        v++;
        c++;
        r++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] == 0) {
                ans[i][j] = v++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
