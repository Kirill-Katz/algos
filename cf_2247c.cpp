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
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int ones = 0;
    int o = 0;
    int z = 0;
    int zz = 0;

    for (int i = 0; i < n; ++i) {
        ones += a[i];

        if (a[i] == 0 && b[i] == 1) {
            z++;
        } else if (a[i] == 1 && b[i] == 0) {
            o++;
        } else if (a[i] == 0 && b[i] == 0) {
            zz++;
        }
    }


    if (o == 0 && z == 0) {
        cout << 0 << '\n';
    } else if (o % 2 == 1) {
        cout << 1 << '\n';
    } else if (o > 0) {
        cout << 2 << '\n';
    } else if (zz != 0 && ones != 0) { // o is 0 at this point because we checked that in the prev. branch
        cout << 2 << '\n';
    } else {
        cout << -1 << '\n';
    }
}
