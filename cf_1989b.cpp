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
    string a, b;
    cin >> a >> b;

    int n_a = a.size();
    int n_b = b.size();

    int ans = INT_MAX;

    for (int i = 0; i < n_b; ++i) {

        int j = i;
        int k = 0;
        while (k < n_a && j < n_b) {
            if (a[k] == b[j]) {
                j++;
            }
            k++;
        }

        ans = min(ans, i + (n_b - j));
    }

    cout << ans + n_a << '\n';
}
