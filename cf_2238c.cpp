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

    vector<vector<int>> g(n + 1);

    g[1].push_back(1);
    for (int i = 2; i <= n; ++i) {
        int p_i = 1;
        cin >> p_i;

        g[p_i].push_back(i);
        g[i].push_back(p_i);
    }

    long long ans = n;

    vector<int> depth(n + 1, 0);
    vector<int> deepest(n + 1, 0);

    auto dfs = [&](auto&& self, int v, int p) -> void {
        deepest[v] = depth[v];

        int mx1 = 0;
        int mx2 = 0;

        for (int to : g[v]) {
            if (to == p) {
                continue;
            }

            depth[to] = depth[v] + 1;
            self(self, to, v);

            deepest[v] = max(deepest[v], deepest[to]);

            int len = deepest[to] - depth[v];

            if (len > mx1) {
                mx2 = mx1;
                mx1 = len;
            } else if (len > mx2) {
                mx2 = len;
            }
        }

        ans += mx2;
    };

    dfs(dfs, 1, 1);
    cout << ans << '\n';
}
