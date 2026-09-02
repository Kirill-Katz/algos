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

constexpr long long mod = 998'244'353;
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // 11 and 00 are imporant, because
    // 01 pairs with 00 on the left, 11 on the right
    // 10 pairs with 11 on the left, 00 on the right
}
