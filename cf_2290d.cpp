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

    vector<char> s(n);
    for (int i = 0; i < n; ++i) {
         cin >> s[i];
    }

    int l = 0, r = n - 1;
    int ans = 0;

    vector<pair<int,int>> segs;

    while (l < r) {
        if (abs(s[r] - s[l])) {
            segs.push_back({ min(s[l], s[r]) - 'a', max(s[r], s[l]) - 'a' });
        }

        l++; r--;
    }

    array<int, 26> prefix{};

    for (auto [l, r] : segs) {
        prefix[l]++;
        prefix[r]--;
    }

    for (int i = 1; i < 26; ++i) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < 26; ++i) {
        ans += prefix[i] != 0;
    }

    cout << ans << '\n';
}
