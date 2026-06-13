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

    // Explanation:
    // A subarray a[l..r] is good if its values are distinct and consecutive.
    // While fixing l and extending r, we can maintain the minimum value, maximum value,
    // and duplicate counts. Then a[l..r] is good exactly when there are no duplicates
    // and mx - mn == r - l.
    //
    // Since we need two subarrays of the same length, the maximum possible length is n / 2.
    // Therefore, for every starting index l, we only need to extend r while the length is <= n / 2.
    // This gives O(n^2) total work.
    //
    // For every good subarray, we store:
    //     pos[l][len] = mn
    // meaning that the subarray starting at l with length len is good and has value interval
    //     [mn, mn + len - 1].
    //
    // Now we need to find two non-overlapping good subarrays of the same length whose value
    // intervals are adjacent. If one good subarray has value interval
    //     [mn, mn + len - 1],
    // then the other one must have minimum value either:
    //     mn - len
    // or:
    //     mn + len.
    //
    // To answer this quickly, we build:
    //     best[mn][len][0] = earliest starting index of a good subarray with minimum mn and length len
    //     best[mn][len][1] = latest starting index of a good subarray with minimum mn and length len
    //
    // Earliest and latest are enough because two subarrays of length len are non-overlapping if
    // one starts at least len positions after the other. So for two value intervals mn1 and mn2,
    // we only need to check:
    //     earliest[mn1] + len <= latest[mn2]
    // or
    //     earliest[mn2] + len <= latest[mn1].
    //
    // Then we iterate over all mn and len, check the adjacent value intervals mn - len and mn + len,
    // and update the answer.

    vector<vector<int>> pos(n, vector<int>(n / 2 + 1, 0));

    for (int l = 0; l < n; ++l) {
        vector<int> cnt(n + 1);
        int mn = n + 1;
        int mx = 0;

        for (int r = l; r < n && r - l + 1 <= n / 2; ++r) {
            int x = a[r];

            cnt[x]++;

            if (cnt[x] > 1) {
                break;
            }

            mn = min(x, mn);
            mx = max(x, mx);
            int len = r - l + 1;

            if (mx - mn == r - l) {
                pos[l][len] = mn;
            }
        }
    }

    vector<vector<array<int, 2>>> best(n + 1, vector<array<int, 2>>(n / 2 + 1, { INT_MAX, -1 }));

    for (int l = 0; l < n; ++l) {
        for (int len = 1; len <= n / 2; ++len) {
            int mn = pos[l][len];

            if (mn == 0) {
                continue;
            }

            best[mn][len][0] = min(best[mn][len][0], l);
            best[mn][len][1] = max(best[mn][len][1], l);
        }
    }

    auto check = [&](int a_mn, int b_mn, int len) {
        if (a_mn < 1 || a_mn > n || b_mn < 1 || b_mn > n) {
            return false;
        }

        if (best[a_mn][len][0] == INT_MAX || best[b_mn][len][0] == INT_MAX) {
            return false;
        }

        int a_first = best[a_mn][len][0];
        int a_last = best[a_mn][len][1];

        int b_first = best[b_mn][len][0];
        int b_last = best[b_mn][len][1];

        if (a_first + len <= b_last) {
            return true;
        }

        if (b_first + len <= a_last) {
            return true;
        }

        return false;
    };

    int ans = 0;
    for (int mn = 1; mn <= n; ++mn) {
        for (int len = 1; len <= n / 2; ++len) {
            if (check(mn, mn - len, len)) {
                ans = max(len, ans);
            }

            if (check(mn, mn + len, len)) {
                ans = max(len, ans);
            }
        }
    }

    cout << ans << '\n';
}
