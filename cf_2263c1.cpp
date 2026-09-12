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

    // if Mex for 2 is something like 3, then there must exist either 0 or 1, because 0 / 2 and 1 / 2 = 0 (where / is floor)
    // there should exit either 2 or 3, because 2 / 2 = 1 and 3 / 2 = 1
    // there should exist eithe 4 or  5 because 4 / 2 = 2, 5 / 2 = 2 and there must not exist 6 or 7, because 6 / 2 and 7 / 2 = 3

    vector<pair<int,int>> excluded;
    for (int i = 0; i < n; ++i) {
        int k = i + 1;

        int left = k * a[i];
        int right = k * (a[i] + 1) - 1;

        excluded.push_back({left, right});
    }

    ranges::sort(excluded);

    vector<int> ans;
    int last_r = 0;
    for (const auto& [l, r] : excluded) {
        if (l > last_r) {
            for (int i = last_r; i < l; ++i) {
                ans.push_back(i);
            }
        }

        last_r = max(last_r, r + 1);
    }

    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
