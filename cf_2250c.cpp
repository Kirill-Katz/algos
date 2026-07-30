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

    vector<pair<int,int>> lr(n);
    vector<pair<int,int>> rr(n);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        lr[i] = {l, r};

        cin >> l >> r;
        rr[i] = {l, r};
    }


    // we can fix m and then we automatically know both left and right ranks for each position
    int ans = 0;

    for (int m = 1; m <= n; ++m) {
        int c = 0;
        int cnt = 0;

        for (int j = 0; j < m; ++j) {
            int left = j + 1;
            int right = m - j;

            while (c < n) {
                auto [l1, r1] = lr[c];
                auto [l2, r2] = rr[c];

                bool wrong = (left >= l1 && left <= r1) || (right >= l2 && right <= r2);

                if (wrong) {
                    c++;
                } else {
                    cnt++;
                    c++;
                    break;
                }
            }
        }

        if (cnt == m) {
            ans = max(ans, cnt);
        }
    }

    cout << ans << '\n';
}
