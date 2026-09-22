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
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ranges::sort(a);

    vector<pair<int, int>> cnt;

    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && a[j] == a[i]) {
            j++;
        }

        cnt.push_back({j - i, a[i]});
        i = j;
    }

    ranges::sort(cnt);

    int F = cnt.back().first;
    int X = cnt.back().second;
    int O = n - F;

    cout << sum - 1LL * X * (F - min(F, O + 2)) << '\n';
}
