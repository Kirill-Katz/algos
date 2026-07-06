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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> k(q);
    for (int i = 0; i < q; ++i) {
        cin >> k[i];
    }

    vector<pair<int,int>> p;

    for (int i = 1; i < n; ++i) {
        p.push_back({ a[i-1], a[i] });
    }

    unordered_map<long long, long long> m;

    for (int i = 0; i < n - 1; ++i) {
        auto [l, r] = p[i];

        m[1LL * (i + 1) * (n - i - 1)] += r - l - 1;
        m[1LL * (i + 1) * (n - i) - 1]++;
    }
    m[1LL * n - 1]++;

    for (long long k_i : k) {
        cout << m[k_i] << ' ';
    }
    cout << '\n';
}
