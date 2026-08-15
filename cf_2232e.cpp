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
    int n, d;
    cin >> n >> d;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // let's start with a simpler problem:
    // assume a subtree is defined only by 2 vertices: a, b.
    //
    // Then we need the minimal connected subgraph containing a and b, that minimal subgraph is the shortest
    // distance between a and b i.e it is equivalent to d(a, b) (count the distance in vertices including both ends)
    // so we would just need to find all the pairs of vertices a and b where d(a, b) = d. Between two vertices there is
    // always exactly one simple path in a tree, so we just need to find vertices a and b where the path between them is includes
    // d vertices.
    //
    // With 3 vertices the problem becomes harder.
    //
    // We could try to firstly fix a and b the same way we did in the easier 2 vertices problem, i.e find
    // the path with distance d between a and b and then c can be any vertex inside that path so for each pair we
    // would get d - 2 possible vertices c.
    //
    // But we wouldn't count all triplets, for that we also need all vertices a and b where the distance between them is
    // d - 1. This way the number of valid vertices which can be picked as c is now equal to the number of first children of
    // any node in that path between a and b, then we would do the same for d - 2, d - 3 etc.
    //
    // the simple implementation would take n^3, but I think a lazy seg tree can be used: compute the number of 1st, 2nd, 3rd etc.
    // nodes of every node, then update all the paths this node is a part of (there are n^2 paths, for n < 2000 it is ok), if we could
    // somehow make these ranged updates log(n) we could have n^2*log(n) which would be fine for this problem.

    vector<int> parent(n + 1), depth(n + 1), order;

    auto dfs = [&](auto&& self, int u, int p) -> void {
        parent[u] = p;
        order.push_back(u);

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, 0);

    vector<vector<int>> dist(n + 1, vector<int>(n + 1));

    for (int s = 1; s <= n; ++s) {
        auto get_dist = [&](auto&& self, int u, int p, int d) -> void {
            dist[s][u] = d;

            for (int v : g[u]) {
                if (v == p) continue;
                self(self, v, u, d + 1);
            }
        };

        get_dist(get_dist, s, 0, 0);
    }

    vector<vector<int>> anc(n + 1, vector<int>(n + 1));

    for (int v = 1; v <= n; ++v) {
        int u = v;

        while (u != 0) {
            anc[v][depth[u]] = u;
            u = parent[u];
        }
    }

    auto lca = [&](int u, int v) {
        int d = (depth[u] + depth[v] - dist[u][v]) / 2;
        return anc[u][d];
    };

    vector<vector<long long>> cnt(n + 1, vector<long long>(n + 1));

    for (int u = 1; u <= n; ++u) {
        for (int v = u; v <= n; ++v) {
            int k = dist[u][v] + 1;
            int x = lca(u, v);

            cnt[u][k]++;
            cnt[v][k]++;
            cnt[x][k]--;

            if (parent[x] != 0) {
                cnt[parent[x]][k]--;
            }
        }
    }

    reverse(order.begin(), order.end());

    for (int u : order) {
        if (parent[u] == 0) continue;

        for (int k = 1; k <= n; ++k) {
            cnt[parent[u]][k] += cnt[u][k];
        }
    }

    long long ans = 0;
    auto dfs_2 = [&](auto&& self, int u, int p, int l = 0) -> void {
        if (d - l > 0) {
            ans += cnt[u][d - l];
        }

        for (int v : g[u]) {
            if (v == p) continue;
            self(self, v, u, l + 1);
        }
    };

    cout << ans << '\n';
}
