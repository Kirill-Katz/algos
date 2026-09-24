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

    unordered_map<long long,long long> cnt;

    long long best = 0;
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        long long ai, c;
        cin >> ai >> c;
        cnt[ai] = c;
        best = max(best, ai);
        total += c;
    }

    auto check = [&](long long val) {
        long long q = 1;
        long long extra = 0;
        val--;

        while (val > 0 && q <= total) {
            if (cnt[val] > q) {
                extra += cnt[val] - q;
            } else {
                q = 2 * q - cnt[val];
            }

            val--;
        }

        if (q > total) {
            return false;
        }

        return q <= cnt[0] + extra;
    };

    long long l = best;
    long long r = 1e9 + 96;

    while (l < r) { // TTTFFF
        long long m = l + (r - l + 1) / 2;

        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}
