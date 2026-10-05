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

    string s;
    cin >> s;

    int sub = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] != s[i] && s[i] != s[i + 1]) {
            if (s[i - 1] != s[i + 1]) {
                sub = max(1, sub);
            } else {
                sub = max(2, sub);
            }
        }
    }

    int blocks = 0;

    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && s[i] == s[j]) {
            j++;
        }

        blocks++;
        i = j;
    }

    cout << blocks - sub << '\n';
}
