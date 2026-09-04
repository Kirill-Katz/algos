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

    auto ask = [&](int u, int v, int d) {
        cout << '?' << ' ' << u << ' ' << v << ' ' << d << '\n';
        cout.flush();

        bool ge;
        cin >> ge;
        return ge;
    };


    auto find_farthest = [&](int u, int mx = 0, int ans) -> pair<int, int> {
        for (int v = 1; v <= n; ++v) {
            if (v == u) continue;

            while (ask(u, v, mx + 1)) {
                mx++;
                ans = v;
            }
        }

        return { ans, mx };
    };

    auto [v, mx] = find_farthest(1, 0, 1);
    auto [u, d] = find_farthest(v, mx, 1);

    cout << '!' << ' ' << v << ' ' << u << ' ' << d << '\n';
    cout.flush();
}
