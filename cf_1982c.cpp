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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l_ = 0;
    long long sum = 0;
    int ans = 0;

    for (int r_ = 0; r_ < n; ++r_) {
        sum += a[r_];

        while (sum >= l && sum > r) {
            sum -= a[l_];
            l_++;
        }

        if (sum >= l) {
            ans++;
            sum = 0;
            l_ = r_ + 1;
        }
    }

    cout << ans << '\n';
}
