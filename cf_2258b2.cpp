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
    long long n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // something related to 2^k, bc if we have all the value < 2^k then at move k we will get sum(a[])

    // at move k we know for sure that one way to get the maximum score is just to sum up all the values <= 2^k
    // OR we could somehow deal with numbers > 2^k

    long long sum = 0;
    vector<long long> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
        sum += a[i];
    }

    vector<long long> suf(m + 1, 0);
    suf[m] = cnt[m];
    for (int i = m - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    vector<long long> answers(m + 1);

    for (int k = 1; k <= m; ++k) {
        if (k >= 31 || (1 << k) > m) {
            answers[k] = sum;
            continue;
        }

        long long max_v = (1 << k);

        long long ans = 0;
        for (long long y = 1; 1LL * y * max_v <= m; ++y) {
            long long local = 0;

            for (int j = 1; j < max_v; ++j) {
                local += 1LL * suf[y * j];
            }

            local += 1LL * cnt[y * max_v];
            ans = max(local, ans);
        }

        answers[k] = ans;
    }

    for (int k = 1; k <= m; ++k) {
        cout << answers[k] << ' ';
    }
    cout << '\n';
}

// void solve_easy() {
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


