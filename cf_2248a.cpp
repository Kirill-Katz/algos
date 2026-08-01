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
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            s.erase(i, 1);
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            s.erase(i, 1);
            break;
        }
    }

    cout << s << '\n';
}
