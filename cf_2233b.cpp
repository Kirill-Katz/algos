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
    // 1234123443211234

    int n;
    cin >> n;

    // 113221332
    // 11312212332
    // 11x12212xx2
    // 21121221

    cout << '\n';

    if (n == 2) {
        cout << "2 1 1 2 1 2 2 1" << '\n';
        return;
    }

    vector<int> ans(4 * n, -1);
    int k = 1;
    for (int i = 0; i < 4 * n; i+=4) {
        ans[i] = k;
        ans[i+1] = k;
        ans[i+3] = k;
        k++;
    }

    int j = n - 1;
    for (int i = 0; i < 4*n; ++i) {
        if (ans[i] == -1) {
            ans[i] = j % n + 1;
            j++;
        }
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';

}
