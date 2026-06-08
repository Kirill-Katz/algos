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

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    auto solve = [&](int p) -> long long {
        long long ans = 0;

        vector<int> pref_max(n);
        pref_max[0] = h[p];

        for (int i = 1; i < n; ++i) {
            int idx = (p + i) % n;
            pref_max[i] = max(pref_max[i - 1], h[idx]);
        }

        vector<int> suf_max(n);
        suf_max[n - 1] = h[(p + n - 1) % n];

        for (int i = n - 2; i >= 0; --i) {
            int idx = (p + i) % n;
            suf_max[i] = max(suf_max[i + 1], h[idx]);
        }

        for (int i = 1; i < n; ++i) {
            ans += min(pref_max[i - 1], suf_max[i]);
        }

        return ans;
    };

    for (int i = 0; i < n; ++i) {
        cout << solve(i) << ' ';
    }

    cout << '\n';
}
