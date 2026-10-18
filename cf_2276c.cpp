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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1);
    prefix[0] = 0;

    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i - 1]) % k;
    }

    vector<int> cnt_right(k + 1, 0);
    // 0, k
    //
    // window of size l [k - 1 elements] r

    for (int i = k + 1; i <= n; ++i) {
        cnt_right[prefix[i]]++;
    }

    long long ans = 0;
    for (int l = 0; l < n - k; ++l) {
        // r - l = k + 1 => r = k + 1 + l
        ans += cnt_right[prefix[l]];
        cnt_right[prefix[l + k + 1]]--;
    }

    cout << ans << '\n';
}
