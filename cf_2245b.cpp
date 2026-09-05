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

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    long long sum = 3;
    vector<long long> ans(n);
    ans[0] = 1;
    ans[1] = 2;

    for (long long i = 2; i < n; ++i) {
        ans[i] = sum;
        sum *= 2;
    }

    for (long long v : ans) {
        cout << v << ' ';
    }

    cout << '\n';
}
