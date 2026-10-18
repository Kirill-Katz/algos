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
    string s;
    cin >> s;

    int n = (int)s.size();
    int remove = 0;
    int add = 0;

    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
            remove = 1;
        }

        if (s[i - 1] == s[i + 1] && s[i] == s[i - 1]) {
            add = 1;
        }
    }

    cout << 1 + remove + add << '\n';
}
