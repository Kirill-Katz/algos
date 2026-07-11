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
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    array<vector<int>, 26> prefix_a;
    array<vector<int>, 26> prefix_b;
    prefix_a.fill(vector<int>(n + 1, 0));
    prefix_b.fill(vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 26; ++c) {
            prefix_a[c][i + 1] = prefix_a[c][i];
            prefix_b[c][i + 1] = prefix_b[c][i];
        }

        prefix_a[a[i]-'a'][i + 1]++;
        prefix_b[b[i]-'a'][i + 1]++;
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        array<int, 26> cnta;
        array<int, 26> cntb;

        for (int c = 0; c < 26; ++c) {
            cnta[c] = prefix_a[c][r + 1] - prefix_a[c][l];
            cntb[c] = prefix_b[c][r + 1] - prefix_b[c][l];
        }

        int ans = r - l + 1;
        for (int c = 0; c < 26; ++c) {
            ans -= min(cnta[c], cntb[c]);
        }
        cout << ans << '\n';
    }
}
