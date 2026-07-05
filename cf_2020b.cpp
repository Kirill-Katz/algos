#include <bits/stdc++.h>
#include <climits>
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
    long long k;
    cin >> k;

    // FFTT

    long long l = 0;
    long long r = LLONG_MAX;

    auto check = [&](long long n) {
        long long r = sqrtl(n);

        while ((r + 1LL) <= n / (r + 1LL)) r++;
        while (r > n / r) r--;

        return n - r >= k;
    };

    while (l < r) {
        long long m = l + (r - l) / 2LL;

        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << '\n';
    return;
}
