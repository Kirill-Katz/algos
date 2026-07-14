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
    long long a, b, k;
    cin >> a >> b >> k;

    // a / b = x / y
    // x <= k and y <= k
    //
    // a * y = x * b if there exist x <= k and y <= k => ans = 1 otherwise 2

    long long g = gcd(a, b);

    long long x = a / g;
    long long y = b / g;

    if (x <= k && y <= k) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}
