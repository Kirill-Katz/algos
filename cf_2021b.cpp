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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    unordered_map<int,int> m;
    int i = 0;

    for (int mex = 0; mex <= n; ++mex) {
        while (i < n && a[i] < mex) {
            m[a[i] % x]++;
            ++i;
        }

        if (i < n && a[i] == mex) {
            i++;
        } else if (m[mex % x]) {
            m[mex % x]--;
        } else {
            cout << mex << '\n';
            return;
        }
    }
}
