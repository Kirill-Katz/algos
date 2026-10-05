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
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(x);
    vector<int> b(y);

    for (int i = 0; i < x; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < y; ++i) {
        cin >> b[i];
    }

    ranges::sort(a, greater<int>());
    ranges::sort(b, greater<int>());

    vector<long long> pref_a(x);
    vector<long long> pref_b(y);

    pref_a[0] = a[0];
    pref_b[0] = b[0];

    for (int i = 1; i < x; ++i) {
        pref_a[i] = pref_a[i - 1] + a[i];
    }

    for (int i = 1; i < y; ++i) {
        pref_b[i] = pref_b[i + 1] + b[i];
    }



}
