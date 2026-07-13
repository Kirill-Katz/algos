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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    if (n % 2 == 0) {
        long long k = 1;
        for (int i = 0; i < n - 1; i += 2) {
            k = max(k, a[i + 1] - a[i]);
        }
        cout << k << '\n';
        return;
    }

    auto check_left = [&](int p) {
        long long k = 1;
        for (int i = 0; i + 1 < p; i += 2) {
            k = max(a[i + 1] - a[i], k);
        }
        return k;
    };

    auto check_right = [&](int p) {
        long long k = 1;
        for (int i = p + 1; i + 1 < n; i += 2) {
            k = max(a[i + 1] - a[i], k);
        }
        return k;
    };

    auto check = [&](long long k) {
        for (int p = 0; p < n; p += 2) {
            if (check_left(p) <= k && check_right(p) <= k) {
                return true;
            }
        }
        return false;
    };

    long long l = 1, r = 1e18;

    // FFTT
    while (l < r) {
        long long m = l + (r - l) / 2;

        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << '\n';
}
