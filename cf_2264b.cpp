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

    vector<int> a(n + 1);
    a[0] = 0;

    for (int i = 1 ; i <= n; ++i) {
        cin >> a[i];
    }

    // we have:
    // sum from i = 1 to m of i * (b_i - b_i-1)
    // if we break down the sum into like this:
    // (b1 - b0) + 2(b2 - b1) + 3(b3 - b2) + 4(b4 - b3) + 5(b5 - b4)
    // We can see that:
    // b1 - b0 + 2b2 - 2b1 + 3b3 - 3b2 + 4b4 - 4b3 + 5b5 - 5b4
    // And thus we get:
    // 5b5 - b4 - b3 - b2 - b1
    //

    multiset<int> my_lovely_set;
    long long current_sum = 0;

    for (int i = 1; i < m; ++i) {
        my_lovely_set.insert(a[i]);
        current_sum += a[i];
    }

    long long ans = LLONG_MIN;
    for (int i = m; i <= n; ++i) {
        ans = max(ans, 1LL * m * a[i] - current_sum);

        if (m == 1) continue;

        int min_v = *my_lovely_set.rbegin();

        if (a[i] < min_v) {
            current_sum += 1LL * a[i] - min_v;

            auto it = prev(my_lovely_set.end());

            my_lovely_set.erase(it);
            my_lovely_set.insert(a[i]);
        }
    }

    cout << ans << '\n';
}
