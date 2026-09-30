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

    vector<pair<int,int>> a(n);
    map<int,int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        cin >> a[i].second;

        if (a[i].first == a[i].second) {
            cnt[a[i].first]++;
        }
    }

    string ans(n, '0');

    vector<int> fixed;
    set<int> used;

    for (auto [l, r] : a) {
        if (l == r && !used.contains(l)) {
            fixed.push_back(l);
            used.insert(l);
        }
    }

    ranges::sort(fixed);

    for (int i = 0; i < n; ++i) {
        auto [l, r] = a[i];
        if (l == r && cnt[l] == 1) {
            ans[i] = '1';
            continue;
        }

        auto it_l = lower_bound(fixed.begin(), fixed.end(), l);
        auto it_r = lower_bound(fixed.begin(), fixed.end(), r);

        if (it_l == fixed.end() || it_r == fixed.end()) {
            ans[i] = '1';
            continue;
        }

        if (*it_l != l || *it_r != r) {
            ans[i] = '1';
            continue;
        }

        if (it_r - it_l + 1 == r - l + 1) {
            continue;
        }

        ans[i] = '1';
    }

    cout << ans << '\n';
}
