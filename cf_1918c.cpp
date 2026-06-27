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
    long long a, b, r;
    cin >> a >> b >> r;


    if (a < b) {
        swap(a, b);
    }

    long long x = 0;
    bool seen_hb = false;

    for (int i = 63; i >= 0; --i) {
        long long bit = 1LL << i;
        long long a_i = (a >> i) & 1;
        long long b_i = (b >> i) & 1;

        if (a_i == b_i) continue;
        if (!seen_hb) {
            seen_hb = true;
            continue;
        }

        if (a_i && !b_i && x + bit <= r) {
            x += bit;
        }
    }

    long long ans = abs((a ^ x) - (b ^ x));
    cout << ans << '\n';
}
