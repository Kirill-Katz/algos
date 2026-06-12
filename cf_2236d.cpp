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

    // 0 <= y - x <= k => x <= y <= k + x

    vector<int> cnt(n + 1);

    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    for (int i = n; i > 0; --i) {
        if (cnt[i] == 0) continue;

        if (cnt[i] % 2 == 0) {
            cout << "YES" << '\n';
            return;
        } else {
            int j = 1;

            while (j <= k && i - j > 0) {
                if (cnt[i - j] != 0) {
                    cout << "YES" << '\n';
                    return;
                }

                j++;
            }

            i -= k;
        }
    }

    cout << "NO" << '\n';
}
