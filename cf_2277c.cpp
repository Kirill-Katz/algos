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

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

         g[u].push_back(v);
         g[v].push_back(u);
    }

    vector<int> op(m);
    for (int i = 0; i < m; ++i) {
        cin >> op[i];
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == 1) continue;

        for (int u : g[v]) {
            if (dist[u] != -1) continue;

            dist[u] = dist[v] + 1;
            q.push(u);
        }

    }

    int ans = dist[1];

    for (int v : op) {
        if (dist[v] == -1) continue;
        ans = max(dist[v] + 1, ans);
    }

    cout << ans << '\n';
}
