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

    unordered_map<long long, int> a;

    long long best = 0;
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        long long v, c;
        cin >> v >> c;
        a[v] = c;

        best = max(v, best);
        total += c;
    }

    auto check = [&](long long v) {
        long long need = 1;
        long long rem = 0;

        for (int i = v - 1; i >= 1; --i) {
            long long have = a[i];

            if (have >= need) {
                rem += have - need;
            } else {
                need += need - have;
            }

            if (need > total) {
                break;
            }
        }

        return rem + a[0]>= need;
    };

    long long l = best, r = 1e9;

    while (l < r) { // TTFF
        long long m = l + (r - l + 1) / 2;

        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}
