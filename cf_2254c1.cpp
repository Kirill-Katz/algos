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

    string a, b;
    cin >> a >> b;

    pair<int,int> a_ones = {0, 0};
    pair<int,int> b_ones = {0, 0};

    pair<int,int> a_zeros = {0, 0};
    pair<int,int> b_zeros = {0, 0};

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            (i % 2 == 0) ? a_ones.first++ : a_ones.second++;
        } else {
            (i % 2 == 0) ? a_zeros.first++ : a_zeros.second++;
        }

        if (b[i] == '1') {
            (i % 2 == 0) ? b_ones.first++ : b_ones.second++;
        } else {
            (i % 2 == 0) ? b_zeros.first++ : b_zeros.second++;
        }
    }

    if (a_ones == b_ones && a_zeros == b_zeros) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
