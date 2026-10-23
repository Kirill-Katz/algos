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

    int max_v = *max_element(a.begin(), a.end());
    int min_v = *min_element(a.begin(), a.end());

    int p = 1;
    int pow = 0;
    while (p <= max_v / 2) {
        p <<= 1;
        pow++;
    }

    bool valid = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != max_v) {
            valid = true;
        }

        if (a[i] <= (p - 1)) {
            cout << (max_v | (p - 1)) << '\n';
            return;
        }
    }

    if (!valid) {
        cout << max_v << '\n';
        return;
    }

    int ans = 0;
    for (int i = pow; i >= 0; --i) {
        int b1 = (max_v >> i) & 1;
        int b2 = (min_v >> i) & 1;

        if (b1 != b2) {
            ans |= (1 << (i + 1)) - 1;
            break;
        }

        ans |= (b1 << i);
    }

    cout << ans << '\n';
}
