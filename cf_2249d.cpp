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
    int n, x;
    cin >> n >> x;

    // d_i(j) = A_i,j ^ A_i+1,j
    // d_i(j + 1) = A_i,j+1 ^ A_i+1,j+1
    //
    // So d_i(j) ^ d_i(j + 1) = x
    //
    // So d_i(j + 1) = d_i(j) ^ x
    //
    // d_i(j + 2) = d_i(j + 1) ^ x <=> d_i(j) ^ x ^ x => d_i(j + 2) = d_i(j)
    //
    // a set {0, 1, ..., 2^k - 1} is closed under XOR
    //
    //

    int cnt = __builtin_popcount(n);
    if (cnt != 1) {
        cout << -1 << '\n';
        return;
    }

    if (n == 2) {
        if (x == 0) {
            cout << "1 0" << '\n';
            cout << "0 1" << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    vector<int> S_diff_G;
    vector<int> G;
    vector<bool> used(n);

    if (x != 0) {
        for (int y = 0; y < n && (int)G.size() < n / 2; ++y) {
            if (used[y]) continue;

            int z = y ^ x;

            used[z] = true;
            used[y] = true;

            G.push_back(z);
            G.push_back(y);
        }
    } else {
        for (int y = 0; y < n / 2; ++y) {
            used[y] = true;
            G.push_back(y);
        }
    }

    for (int v = 0; v < n; ++v) {
        if (!used[v]) S_diff_G.push_back(v);
    }

    vector<int> h(n);

    int o = 0, e = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            h[i] = S_diff_G[e];
            e++;
        } else {
            h[i] = G[o];
            o++;
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        ans[0][i] = h[i];
    }

    for (int i = 1; i < n; ++i) {
        int a = h[i] ^ h[i-1];

        for (int j = 0; j < n; ++j) {
            ans[i][j] = ans[i-1][j] ^ a ^ ((j % 2) * x);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
