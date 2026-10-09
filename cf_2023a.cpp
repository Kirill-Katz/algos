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

    vector<pair<int, pair<int,int>>> a(n);
    for (int i = 0; i < n; ++i) {
        int a1, a2;
        cin >> a1 >> a2;
        a[i] = { a1 + a2, {a1, a2} };
    }

    ranges::sort(a);

    for (auto v : a) {
        auto [s, p] = v;
        auto [a1, a2] = p;
        cout << a1 << ' ' << a2 << ' ';
    }
    cout << '\n';
}
