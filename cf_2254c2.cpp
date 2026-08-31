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

    string a;
    string b;
    cin >> a;
    cin >> b;

    // we can think about this problem as having to reorder a string to match another string.
    // in other words we know that the first 1 in the string a has to go to the position of the
    // first 1 in b, the same for the second 1 and so on.
    //
    // How do we know if we can put a 1 at some position? assume the true position is i and the 1 is at j
    // For that to be true there are 2 conditions, either:
    // 1. abs(i - j) is even (then we can use operation 1)
    // 2. abs(i - j) is odd, but there exists a 1 to the right at position k such that abs(i - k) is even
    // which allows to switch the parity of ones with respect to their destination, so the rule is that both ones
    // at i and k should have abs(i_j - i) odd and (k_j - k) odd (where i_j and k_j are target positions)
    //

    vector<int> odd_a;
    vector<int> odd_b;

    vector<int> even_a;
    vector<int> even_b;

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            if (i % 2) {
                odd_a.push_back(i);
            } else {
                even_a.push_back(i);
            }
        }

        if (b[i] == '1') {
            if (i % 2) {
                odd_b.push_back(i);
            } else {
                even_b.push_back(i);
            }
        }
    }

    if (odd_a.size() != odd_b.size() || even_a.size() != even_b.size()) {
        cout << -1 << '\n';
        return;
    }

    int o = odd_a.size();
    int e = even_a.size();

    long long ans = 0;
    for (int i = 0; i < o; ++i) {
        ans += (abs(odd_a[i] - odd_b[i]) / 2);
    }

    for (int i = 0; i < e; ++i) {
        ans += (abs(even_a[i] - even_b[i]) / 2);
    }

    cout << ans << '\n';
}
