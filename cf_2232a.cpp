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

    sort(a.begin(), a.end());
    int median = n % 2 ? a[n / 2] : ((a[n / 2 - 1] + a[n / 2]) / 2);
    int ans = 0;

    for (int l = 0; l < n / 2; ++l) {
        int r = n - 1 - l;
        if (a[l] != median || a[r] != median) {
            ans++;
        }
    }

    cout << ans << '\n';
}
