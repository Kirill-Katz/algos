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

    vector<vector<int>> g(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int v = 1; v <= n; ++v) {
        if (g[v].empty()) {
            cout << "Brain Melt" << '\n';
            return;
        }
    }

    int center = 1;
    for (int v = 2; v <= n; ++v) {
        if (g[v].size() > g[center].size()) {
            center = v;
        }
    }

    bool star = g[center].size() == n - 1;

    for (int v = 1; v <= n; ++v) {
        if (v == center) continue;

        if (g[v].size() != 1) {
            star = false;
        }
    }
    cout << (star ? "2" : "Many") << '\n';
}
