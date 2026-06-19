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

    vector<int> a(n);
    vector<int> b(n);

    multiset<int> b_set;

    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(a[i], max_val);
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b_set.insert(b[i]);
    }

    for (int i = 0; i < n; ++i) {
        auto it = b_set.lower_bound(a[i]);
        if (it == b_set.end()) {
            cout << -1 << '\n';
            return;
        }

        a[i] = *it;
        b_set.erase(it);
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
