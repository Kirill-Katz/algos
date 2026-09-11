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

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    string s(n, '0');

    vector<pair<int,int>> segs;

    for (int i = 0; i < n; ++i) {
        if (b[i] == -1) {
            continue;
        }

        int l = max(i - b[i] + 1, 0);
        int r = min(i + b[i] - 1, n - 1);

        if (l <= r) {
            segs.push_back({ l, r });
        }
    }

    std::ranges::sort(segs);

    int last_r = 0;
    for (const auto& [l, r] : segs) {
        if (l > last_r) {
            for (int i = last_r; i < l; ++i) {
                s[i] = '1';
            }
        }

        last_r = max(last_r, r + 1);
    }

    for (int i = last_r; i < n; ++i) {
        s[i] = '1';
    }

    if (segs.empty()) {
        s = string(n, '1');
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] == -1) {
            continue;
        }

        int d = b[i];

        bool ok = false;

        if (i - d >= 0 && s[i - d] == '1') {
            ok = true;
        }

        if (i + d < n && s[i + d] == '1') {
            ok = true;
        }

        if (!ok) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << s << '\n';
}
