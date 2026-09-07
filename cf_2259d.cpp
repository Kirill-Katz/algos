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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[i] = {v, i};
    }

    sort(a.begin(), a.end());

    array<char, 3> cmap = {'a', 'b', 'c'};
    string ans;
    ans.resize(n);

    array<vector<int>, 3> sets;

    int mod = 0;
    sets[mod].push_back(a[0].first);
    ans[a[0].second] = 'a';
    mod++;

    for (int i = 1; i < n; ++i) {
        auto [val, idx] = a[i];

        if (a[i].first == a[i - 1].first) {
            sets[mod].push_back(val);
        } else {
            mod = 0;
            sets[mod].push_back(val);
        }

        ans[idx] = cmap[mod];
        mod = (mod + 1) % 3;
    }

    auto mex = [&](const auto& vec) {
        int need = 0;

        for (int v : vec) {
            if (v == need) need++;
        }

        return need;
    };

    cout << mex(sets[0]) << ' ' << mex(sets[1]) << ' ' << mex(sets[2]) << '\n';

    if (mex(sets[0]) + mex(sets[1]) + mex(sets[2]) >= 2 * max({ mex(sets[0]), mex(sets[1]), mex(sets[2]) })) {
        cout << "YES" << '\n';
        cout << ans << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
