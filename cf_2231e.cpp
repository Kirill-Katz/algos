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
    // Root the tree at 1. We can just compute the number of paths of size k (for each k) that a vertex is a part of in its subtree,
    // then we can compute the distance from that vertex to the "outside vertices".

    vector<vector<int>> up(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> down(n + 1, vector<int>(n + 1, -1));

    vector<vector<int>> up_cnt(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> down_cnt(n + 1, vector<int>(n + 1, 0));

    vector<vector<int>> subtree(n + 1, vector<int>());
    vector<vector<int>> children(n + 1, vector<int>());

    auto dist_down = [&](auto&& self, int v, int p) -> void {
        down[v][v] = 0;

        for (int u : g[v]) {
            if (u == p) continue;

            self(self, u, v);

            for (int other = 1; other <= n; ++other) {
                if (down[u][other] != -1) {
                    down[v][other] = down[u][other] + 1;
                }
            }
        }
    };

    auto dist_up = [&](auto&& self, int r, int v, int p, int l = 0) -> void {
        if (down[r][v] == -1) {
            up[r][v] = l;
        }

        for (int u : g[v]) {
            if (u == p) continue;
            self(self, r, u, v, l + 1);
        }
    };

    auto compute_subtrees = [&](auto&& self, int v, int p) -> void {
        subtree[v].push_back(v);

        for (int u : g[v]) {
            if (u == p) continue;
            children[v].push_back(u);

            self(self, u, v);

            for (int node : subtree[u]) {
                subtree[v].push_back(node);
            }
        }
    };

    auto aggregate_dist_up = [&](int node) -> void {
        for (int u = 1; u <= n; ++u) {
            if (up[node][u] != -1) {
                up_cnt[node][up[node][u]]++;
            }
        }
    };

    auto aggregate_dist_down = [&](int node) -> void {
        for (int u = 1; u <= n; ++u) {
            if (down[node][u] != -1) {
                down_cnt[node][down[node][u]]++;
            }
        }
    };

    dist_down(dist_down, 1, 0);
    compute_subtrees(compute_subtrees, 1, 0);

    for (int v = 1; v <= n; ++v) {
        dist_up(dist_up, v, v, 0);
    }

    for (int v = 1; v <= n; ++v) {
        aggregate_dist_down(v);
        aggregate_dist_up(v);
    }

    long long ans = 0;
    auto cnt = [&](int node) -> void {
        long long ans_up = 0;
        long long ans_down = 0;
        for (int i = 0; i < (int)children[node].size(); ++i) {
            for (int j = i + 1; j < (int)children[node].size(); ++j) {
                int child_left = children[node][i];
                int child_right = children[node][j];

                for (int u : subtree[child_left]) {
                    for (int v : subtree[child_right]) {
                        int len = down[node][u] + down[node][v];

                        if (len > d - 1) {
                            continue;
                        }

                        if (len == d - 1) {
                            ans += d - 2;
                        } else {
                            int rem = d - 1 - len;

                            ans_down += down_cnt[node][rem] -
                                down_cnt[child_left][rem - 1] -
                                down_cnt[child_right][rem - 1];

                            ans_up += up_cnt[node][rem];
                        }
                    }
                }
            }
        }

        for (int child : children[node]) {
            for (int u : subtree[child]) {
                if (down[node][u] == d - 1) {
                    ans += d - 2;
                }
            }
        }

        ans += ans_down / 3;
        ans += ans_up;
    };

    for (int v = 1; v <= n; ++v) {
        cnt(v);
    }

    cout << ans << '\n';
}
