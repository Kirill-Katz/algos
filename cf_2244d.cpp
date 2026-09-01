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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // we can sort the values in b ascending, in this case if we apply b[0] then b[1] only the values in (b[0], b[1]]
    // will change.
    //
    // After we apply b[0] we change values in [0, b[0]], after we apply b[1] we returned values in [0, b[0]] to their prev state
    // and then changed values in (b[0], b[1]], applying b[3] changes values in [0, b
    //
    //

    b.push_back(0);
    sort(b.begin(), b.end());

    vector<long long> prefix(n + 1);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    long long ans = 0;
    for (int i = 1; i <= m; ++i) {
        long long local = prefix[b[i]] - prefix[b[i - 1]];
        ans += abs(local);
    }

    ans += prefix[n] - prefix[b[m]];

    cout << ans << '\n';
}
