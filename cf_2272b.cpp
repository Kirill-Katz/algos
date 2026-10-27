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

    vector<vector<char>> a(2, vector<char>(n));

    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[1][i];
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += (a[0][i] == 'f') + (a[1][i] == 'f');
    }

    cout << total % 2 << '\n';
}
