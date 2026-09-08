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

    vector<pair<int, int>> a(n);

    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[i] = {v, i};
        zeros += v == 0;
    }

    sort(a.begin(), a.end());

    string ans;
    ans.resize(n);

    if (zeros != 1) {
        cout << "YES" << '\n';

        int i = 0;
        ans[a[i].second] = 'A';
        ++i;

        while (i < n && a[i].first == 0) {
            ans[a[i].second] = 'B';
            ++i;
        }

        while (i < n) {
            ans[a[i].second] = 'C';
            ++i;
        }

        cout << ans << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
