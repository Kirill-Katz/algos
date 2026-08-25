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
    // -1 for all k < number of leaves, because if k < number of leaves =>
    // two leaves will be in the same set S_i, but by definition leaf l1 and leaf l2 cannot be ancestors of
    // each other
    //
    // We can call the default configuration the configuration for k = # of leaves.
    // In this configuration we will have k sets of paths from a leaf l_i to some vertex v_i for every leaf.
    //
    // We want to maximize the score in this configuration, so we want to have the maximum leaves as "single" as possible
    // and small leaves to be in a set representing a longer path. So we can go bottom up and compare all the leaves on some
    // level, the smallest one will be a part of the set containing their parent leaf, after that we do the same for the parent leaf
    // and so on. In the end we will obtain k sets, representing k paths, we can sort them in increasing order.
    //
    // When increasing k by 1 we want to pick the set with the largest n - 1 element because that will allow us to make the element at
    // n its own set and then gain exactly a[u at n - 1 in that set] score.
    //
    // Picking the initial config is the hard part, because if we had that, we could do the stated above greedy strategy.
    // The best possible outcome is to find the k maximum vertices in that set and to split the tree in k sets each containing
    // exactly one such maximum. This might not be possible however, because in the default split we aren't allowed to have a path
    // that doesn't go from a leaf l to a vertex v with more than 2 children.

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int u = 1; u <= n; ++u) {
        cin >> a[u];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;

        g[p].push_back(i);
        g[i].push_back(p);
    }

    int leaves = 0;

    auto dfs = [&](auto&& self, int u, int p) {
        bool is_leaf = true;

        for (int v : g[u]) {
            if (u == p) continue;

            is_leaf = false;
            self(self, v, u);
        }

        if (is_leaf) leaves++;
    };



}
