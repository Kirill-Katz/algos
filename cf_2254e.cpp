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

    long long total = 0;
    multiset<int> neg;
    multiset<int> pos;

    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;

        if (v > 0) {
            pos.insert(v);
        } else {
            neg.insert(abs(v));
        }
        total += v;
    }

    vector<long long> ans;
    if (total <= 0) {
        cout << -1 << '\n';
        return;
    }

    ans.push_back(*pos.begin());
    long long current = *pos.begin();

    pos.erase(pos.begin());

    for (int i = 0; i < n - 1; ++i) {
        auto it_neg = neg.lower_bound(current);

        if (it_neg == neg.begin()) {
            auto it_pos = pos.begin();
            current += *it_pos;
            pos.erase(it_pos);
        } else {
            --it_neg;
            current -= *it_neg;
            neg.erase(it_neg);
        }

        ans.push_back(current);
    }

    for (long long v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
