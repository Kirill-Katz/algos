#include <algorithm>
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < q; ++i) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);

        if (it == b.begin()) {
            cout << *b.begin() - 1 << '\n';
            continue;
        }

        if (it == b.end()) {
            cout << n - *prev(b.end()) << '\n';
            continue;
        }

        if (a[i] == *prev(it)) {
            cout << 0 << '\n';
            continue;
        }

        cout << (*it - *prev(it)) / 2 << '\n';
    }
}
