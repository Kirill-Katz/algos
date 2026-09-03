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

solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // something related to 2^k, bc if we have all the value < 2^k then at move k we will get sum(a[])

    // at move k we know for sure that one way to get the maximum score is just to sum up all the values <= 2^k
    // OR we could somehow deal with numbers > 2^k


}

// void solve() {
//     int n, m;
//     cin >> n >> m;
//
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//
//     sort(a.begin(), a.end());
//
//     // for k = 1, if we choose an x, then we get +1 for all the numbers >= x and we get +2 for all the numbers k = 2 * x
//     //
//     //
//     // for k = 2,
//     //
//
//     vector<int> cnt(m + 1, 0);
//     for (int i = 0; i < n; ++i) {
//         cnt[a[i]]++;
//     }
//
//     vector<int> suf(m + 1, 0);
//     suf[m] = cnt[m];
//     for (int i = m - 1; i >= 0; --i) {
//         suf[i] = suf[i + 1] + cnt[i];
//     }
//
//     int ans = n;
//     for (int i = 1; i <= m / 2; ++i) {
//         ans = max(ans, suf[i] + cnt[i * 2]);
//     }
//
//     cout << ans << '\n';
// }
//


