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

    // for 2 numbers this thing is easy: just take 1 then n, then 2 and n - 1 then 3 and n - 2 etc.
    // which will result in th same value if n is even. If it is not even then we take
    //
    // maybe n, 1, n - 2, 2, n - 3, 3, n - 4, here every k = 2 window has the sum diff at most 1.
    //
    // n - 1, 1, n - 2, 2, n - 3, 3
    //
    // 1, n, 3, n - 2, 2, n - 1, 4, n - 3 this is probably correct
    // idea:
    // i % 2 == 0 => we increase every k + 1
    // i % 2 == 1 => we decrease every k + 1
    // Thus we get the invariant that while sliding the window we get +1, -1, +1, -1 to the sum, the sum
    // inside the first window s_0, then s_1 = s_0 + 1, s_2 = s_0, s_3 = s_0 + 1. QED.

    vector<int> ans(n);
    int cur = 1;

    for (int i = 0; i < k; ++i) {
        int tmp = cur;

        int cnt = 0;
        for (int j = i; j < n; j += k) {
            ans[j] = tmp;

            if (i % 2 == 0) {
                tmp++;
            } else {
                tmp--;
            }
            cnt++;
        }

        if (i % 2 == 0) {
            cur += cnt - 1;
            cur += (n - 1 - i + k - 1) / k;
        } else {
            cur++;
        }
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
