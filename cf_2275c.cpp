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

    map<int, int> cnt;

    auto score = [&](int i) {
        if (i + 4 >= n) {
            return INT_MIN;
        }
        return a[i] + a[i + 2] - a[i + 4];
    };

    for (int i = 0; i + 4 < n; i++) {
        cnt[score(i)]++;
    }

    long long ans = 0;
    for (int i = 0; i + 4 < n; i++) {
        long long v = score(i);
        long long matches = --cnt[v];

        if (score(i + 2) == v) matches--;
        if (score(i + 4) == v) matches--;

        ans += matches;
    }


    // n choose 2 = n! / (n - 2)! * 2 = (n - 1) * n / 2

    cout << ans << '\n';
}
