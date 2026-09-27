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
    int odd = 0;
    int even_0 = 0;
    int even_1 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] & 1) {
            odd++;
        } else {
            even_0 += (a[i] / 2) % 2 == 0;
            even_1 += (a[i] / 2) % 2 == 1;
        }
    }

    cout << max({ odd, even_0, even_1 }) << '\n';
}
