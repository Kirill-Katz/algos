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

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // a[i] > a[i + 1]
    // 4 3 6 7

    auto dfs = [&] (auto&& self, int v, int p) -> pair<int,int> {
        bool is_leaf = true;

        vector<pair<int,int>> acc;

        for (int u : g[v]) {
            if (u == p) {
                continue;
            }
            is_leaf = false;

            auto pr = self(self, u, v);
            acc.push_back(pr);

            if (pr.first == -1 && pr.second == -1) {
                return {-1, -1};
            }
        }

        if (is_leaf) {
            return { a[v], a[v] };
        }

        int an = acc.size();
        int broken = 0;

        int min_l = INT_MAX;
        int max_r = INT_MIN;

        for (int i = 0; i < an; ++i) {
            min_l = min(min_l, acc[i].first);
            max_r = max(max_r, acc[i].second);
            if (acc[i].second > acc[(i + 1) % an].first) {
                broken++;
            }
        }

        if (broken > 1) {
            return {-1, -1};
        }

        return {min_l, max_r};
    };

    auto [l, r] = dfs(dfs, 1, 0);

    if (l == -1 && r == -1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

