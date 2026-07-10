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

    string s;
    cin >> s;

    vector<long long> prefix(n + 1);
    prefix[0] = 0;

    for (int i = 1; i <= n; ++i) {
        prefix[i] = a[i-1] + prefix[i-1];
    }

    int l = 0;
    int r = n - 1;

    long long ans = 0;

    while (l < r) {
        if (s[l] == 'R') {
            l++;
            continue;
        }

        if (s[r] == 'L') {
            r--;
            continue;
        }

        ans += prefix[r + 1] - prefix[l];
        l++;
        r--;
    }

    cout << ans << '\n';
}
