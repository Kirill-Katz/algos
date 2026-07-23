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
    vector<vector<int>> b(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c-'0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        int sum_per_row_a = 0;
        int sum_per_row_b = 0;

        for (int j = 0; j < m; ++j) {
            sum_per_row_a += a[i][j];
            sum_per_row_b += b[i][j];
        }

        if (sum_per_row_a % 3 != sum_per_row_b % 3) {
            cout << "NO"  << '\n';
            return;
        }
    }

    for (int j = 0; j < m; ++j) {
        int sum_per_col_a = 0;
        int sum_per_col_b = 0;

        for (int i = 0; i < n; ++i) {
            sum_per_col_a += a[i][j];
            sum_per_col_b += b[i][j];
        }

        if (sum_per_col_a % 3 != sum_per_col_b % 3) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
