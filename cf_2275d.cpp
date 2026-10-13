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
    long long n;
    long long k;

    cin >> n;
    cin >> k;

    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    vector<long long> towers;
    long long base = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        towers.push_back(a[i] + b[i] + c[i]); // needs a cost to be increased by 1
                                              // cost is always negative so +
    }

    auto check = [&](long long level) {
        long long need = 0;

        for (int i = 0; i < (int)towers.size(); ++i) {
            if (level <= towers[i]) {
                continue;
            }

            if (a[i] == b[i] && b[i] == c[i]) {
                return false;
            }

            long long total_cost = towers[i];

            if (a[i] <= b[i] && b[i] <= c[i]) {
                long long cost = LLONG_MIN;
                cost = max({ a[i] - b[i] - 1, a[i] - c[i] - 1, b[i] - c[i] - 1 });
                total_cost += 2 * cost;
            }

            need += max(0LL, level - total_cost);

            if (need > k) {
                return false;
            }
        }

        return need <= k;
    };

    long long l = *min_element(towers.begin(), towers.end());
    long long r = *max_element(towers.begin(), towers.end()) + k;

    while (l < r) { // TTFF
        long long m = l + (r - l + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << min(l, base) << '\n';
}
