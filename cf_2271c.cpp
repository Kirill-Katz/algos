#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

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

    int p = 1;
    while (p <= n / 2) {
        p *= 2;
    }

    vector<int> target_prefix;
    for (int i = 0; i < 2 * p; ++i) {
        target_prefix.push_back(i ^ (i >> 1));
    }
    for (int i = 0; i < 2 * p; ++i) {
        target_prefix.push_back(i ^ (i >> 1));
    }

    vector<int> ans;
    ans.reserve(2 * p - 1);

    for (int i = 1; i < (int)target_prefix.size(); ++i) {
        ans.push_back(target_prefix[i - 1] ^ target_prefix[i]);
    }

    cout << (int)ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }

    cout << '\n';
}
