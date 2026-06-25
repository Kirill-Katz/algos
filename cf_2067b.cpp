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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> cnt(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) continue;
        if (cnt[i] == 1) {
            cout << "NO" << '\n';
            return;
        }

        if (i + 1 <= n) {
            cnt[i + 1] += cnt[i] - 2;
            cnt[i] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] % 2 == 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
