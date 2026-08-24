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

    vector<int> p(n + 1);
    vector<vector<int>> g(n + 1);
    p[1] = 0;

    for (int i = 2; i <= n; ++i) {
        int pr;
        cin >> pr;
        p[i] = pr;

        g[pr].push_back(i);
        g[i].push_back(pr);
    }

    int m;
    cin >> m;
    vector<int> a(m);

    bool free = false;
    int free_v = -1;

    vector<bool> is_dam(n + 1, false);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        is_dam[a[i]] = true;
    }

    if (is_dam[1]) {
        free = true;
        free_v = 1;
    }

    auto dfs = [&](auto&& self, int u, int p) {
        bool is_u_dam = is_dam[u];

        if (is_u_dam) {
            free = true;
            free_v = u;
            return true;
        }

        for (int v : g[u]) {
            if (v == p) continue;
            if (self(self, v, u)) {
                return true;
            }
        }

        return false;
    };

    if (!free) {
        dfs(dfs, 1, 0);
    }

    cout << m - free << ' ';

    for (int i = 0; i < m; ++i) {
        if (a[i] != free_v) cout << a[i] << ' ';
    }

    cout << '\n';
}
