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
    int l, r;
    cin >> l >> r;

    int fac = 1;
    int pow = 0;

    int cpy = l;
    while (cpy > 0) {
        cpy /= 3;

        fac *= 3;
        pow++;
    }

    int c = l;
    long long sum = pow;

    while (fac <= r) {
        sum += (fac - c) * pow;
        c = fac;

        pow++;
        fac *= 3;
    }

    sum += (r - c + 1) * pow;

    cout << sum << '\n';
}
