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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == 1) {
        cout << -1 << '\n';
        return;
    }


    auto x = max_element(a.begin(), a.begin() + n - k + 1) - a.begin();
    auto y = min_element(a.begin() + n - k + 1, a.end()) - a.begin();

    if (a[x] > a[y]) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

