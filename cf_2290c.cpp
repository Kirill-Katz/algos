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

    vector<int> a(n);
    map<int, int> s;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[a[i]]++;
    }

    vector<int> left;
    vector<int> right;

    ranges::sort(a);
    int k = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (i % 2) {
            if (left.empty() || left.back() != a[i]) {
                k++;
            }

            left.push_back(a[i]);
        } else {
            if (right.empty() || right.back() != a[i]) {
                k++;
            }

            right.push_back(a[i]);
        }
    }

    cout << k + (s[a[n - 1]] <= 2) << '\n';
    ranges::sort(left);

    for (auto v : left) {
        cout << v << ' ';
    }

    cout << a[n - 1] << ' ';

    for (auto v : right) {
        cout << v << ' ';
    }

    cout << '\n';
}
