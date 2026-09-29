
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

    // aaabbb
    // aababb
    //
    // 1 1 2 1 1 3
    //
    //

    vector<pair<int,int>> b;
    int ans = 0;

    for (int i = 0; i < n;) {
        int j = i;

        int cnt = 0;
        while (j < n && a[j] == a[i]) {
            cnt++;
            j++;
        }

        b.push_back({ a[i], cnt });
        i = j;
        ans++;
    }


    int add = 0;
    for (int i = 0; i < (int)b.size() - 1; ++i) {
        if (b[i].second >= 2 && b[i + 1].second >= 2) {
            add = max(add, 2);
        }

        if (i == 0) continue;

        if (b[i + 1].first != b[i - 1].first && (b[i + 1].second >= 2 || b[i - 1].second >= 2)) {
            add = max(1, add);
        }
    }

    if (b.size() > 1) {
        if (b[1].second >= 2) {
            add = max(1, add);
        }

        if (b[b.size() - 2].second >= 2) {
            add = max(1, add);
        }

    }

    cout << ans + add << '\n';
}
