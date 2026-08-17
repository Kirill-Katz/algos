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

using ll = long long;

const int MOD = 998244353;
const int G = 3;

int mod_pow(int a, int e) {
    ll r = 1;

    while (e) {
        if (e & 1) {
            r = r * a % MOD;
        }

        a = (ll)a * a % MOD;
        e >>= 1;
    }

    return (int)r;
}

void ntt(vector<int>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;

        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }

        j ^= bit;

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = mod_pow(G, (MOD - 1) / len);

        if (invert) {
            wlen = mod_pow(wlen, MOD - 2);
        }

        for (int i = 0; i < n; i += len) {
            ll w = 1;

            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = (int)(a[i + j + len / 2] * w % MOD);

                a[i + j] = u + v;

                if (a[i + j] >= MOD) {
                    a[i + j] -= MOD;
                }

                a[i + j + len / 2] = u - v;

                if (a[i + j + len / 2] < 0) {
                    a[i + j + len / 2] += MOD;
                }

                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        int inv_n = mod_pow(n, MOD - 2);

        for (int& x : a) {
            x = (ll)x * inv_n % MOD;
        }
    }
}

vector<int> convolution(vector<int> a, vector<int> b) {
    int need = a.size() + b.size() - 1;
    int n = 1;

    while (n < need) {
        n <<= 1;
    }

    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);

    for (int i = 0; i < n; ++i) {
        a[i] = (ll)a[i] * b[i] % MOD;
    }

    ntt(a, true);
    a.resize(need);

    return a;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 1. Every diameter is by definition a simple path from a leaf to a leaf.
    // 2. A tree being acyclical, connected and with an odd diameter means that all diameters will be forced to go though a
    // shared edge r, otherwise either the tree is disconnected or there is a longer path that does go through r.
    // 3. Take the edge r which connectes two nodes (which is required to be true for the diameter being odd)
    // the graph can be split into two parts: the left subtree rooted at the left node of r and the right subtree rooted at
    // the right node of r.
    // 4.
    //

    int max_d = -1;
    int farthest = -1;

    auto find_farthest = [&](auto&& self, int u, int p, int d = 0) -> void {
        if (d > max_d) {
            max_d = d;
            farthest = u;
        }

        for (int v : g[u]) {
            if (v == p) continue;
            self(self, v, u, d + 1);
        }
    };

    find_farthest(find_farthest, 1, 0, 0);

    int from = farthest;
    max_d = -1;
    farthest = -1;

    find_farthest(find_farthest, from, 0, 0);
    int to = farthest;

    vector<int> farthest_path;
    auto find_path = [&](auto&& self, int to, int u, int p, vector<int>& path) -> bool {
        if (u == to) {
            farthest_path = path;
            return true;
        }

        for (int v : g[u]) {
            if (v == p) continue;
            path.push_back(v);
            if (self(self, to, v, u, path)) {
                return true;
            }

            path.pop_back();
        }

        return false;
    };

    vector<int> tmp = {from};
    find_path(find_path, to, from, 0, tmp);

    int left_r = farthest_path[(int)farthest_path.size() / 2 - 1];
    int right_r = farthest_path[(int)farthest_path.size() / 2];

    vector<bool> left_vals(max_d / 2 + 1, false);
    vector<bool> right_vals(max_d / 2 + 1, false);

    auto dfs = [&](auto&& self, int u, int p, int l = 0, vector<bool>& has) -> bool {
        int deep_child_cnt = 0;
        bool is_leaf = true;

        for (int v : g[u]) {
            if (v == p) continue;
            is_leaf = false;

            if (self(self, v, u, l + 1, has)) {
                deep_child_cnt++;
            }
        }

        if (deep_child_cnt >= 2) {
            has[l] = true;
        }

        if (is_leaf) {
            if (max_d / 2 == l) {
                has[max_d / 2] = true;
            }
            return l == max_d / 2;
        }

        return deep_child_cnt > 0;
    };

    dfs(dfs, left_r, right_r, 0, left_vals);
    dfs(dfs, right_r, left_r, 0, right_vals);

    vector<bool> ans(max_d + 1, false);
    ans[max_d] = true;

    vector<int> a(max_d / 2 + 1);
    vector<int> b(max_d / 2 + 1);

    for (int i = 0; i <= max_d / 2; ++i) {
        a[i] = right_vals[i];
        b[i] = left_vals[i];
    }

    vector<int> conv = convolution(a, b);
    for (int i = 0; i < (int)conv.size(); ++i) {
        if (conv[i] != 0 && i + 1 < (int)ans.size()) {
            ans[i + 1] = true;
        }
    }

    int total = 0;
    for (int i = 1; i <= max_d; ++i) {
        if (ans[i]) {
            total++;
        }
    }

    cout << total << ' ';
    for (int i = 1; i <= max_d; ++i) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}
