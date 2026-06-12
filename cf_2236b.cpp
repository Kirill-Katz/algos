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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    for (int i = 0; i < k; ++i) {
        int cnt = 0;
        for (int j = i; j < n; j += k) {
            if (s[j] == '1') {
                cnt++;
            }
        }

        if (cnt % 2 == 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
