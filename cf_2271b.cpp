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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ranges::sort(a);

    vector<pair<int,int>> blocks;
    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && a[i] == a[j]) {
            ++j;
        }

        blocks.push_back({ a[i], j - i});
        i = j;
    }

    if (blocks[0].first != 0) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < (int)blocks.size(); ++i) {
        auto [v, c] = blocks[i];

        if (i > 0 && v != blocks[i - 1].first + 1) {
            break;
        }

        if (k * 2 - 1 == c) {
            cout << "YES" << '\n';
            return;
        } else if (2 * k - 1 > c) {
            break;
        }
    }

    cout << "NO" << '\n';
}
