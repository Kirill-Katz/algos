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

    map<int,int> p_factors;
    int tmp = n;

    for (int c = 2; 1LL * c * c <= tmp; ++c) {
        while (tmp % c == 0) {
            p_factors[c]++;
            tmp /= c;
        }
    }

    if (tmp > 1) {
        p_factors[tmp]++;
    }

    int total = 0;
    int base = 0;
    for (auto [p, c] : p_factors) {
        total += c;
        base++;
    }

    cout << base + total - 1 << '\n';
}
