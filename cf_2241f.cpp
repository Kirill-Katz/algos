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

    // if the total number of inversions is odd Alice automatically wins, so this algorithm needs to be applied only when there
    // is an even number of inversions in the string.
    //
    // what she can do is try to remove all the 1s or all the 0s, this way there will be no inversions by definition. To do that:
    // - for all the ones to be removed in one more there must exist a 0 such that the number of 1s to its left is odd
    // - symmetrically for all zeros to be removed
    //
    // 111100

    vector<int> zs(n);
    vector<int> os(n);

    os[0] = s[0] == '1';
    zs[n-1] = s[n-1] == '0';

    for (int i = 1; i < n; ++i) {
        os[i] = os[i - 1] + (s[i] == '1');
    }
    for (int i = n - 2; i >= 0; --i) {
        zs[i] = zs[i + 1] + (s[i] == '0');
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (zs[i] % 2 == 1) {
                cout << "Alice" << '\n';
                return;
            }
        } else {
            if (os[i] % 2 == 1) {
                cout << "Alice" << '\n';
                return;
            }
        }
    }

    cout << "Bob" << '\n';
}
