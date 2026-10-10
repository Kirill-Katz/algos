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
    int even = 0;
    int odd = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        even += a[i] % 2 == 0;
        odd += a[i] % 2 == 1;
    }

    if (even && odd) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    while (true) {
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        if (mx == 0) {
            break;
        }

        int v = mn + (mx - mn) / 2;
        ans.push_back(v);
        for (int& x : a) {
            x = abs(x - v);
        }
    }

    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }

    cout << '\n';
}
