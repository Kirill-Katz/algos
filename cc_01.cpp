#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    freopen("lvl1_bg.in", "r", stdin);
    freopen("lvl1_bg.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (t--) solve();

    return 0;
}

void solve() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> a;
    int x;
    while (ss >> x)
        a.push_back(x);

    long long ans = 0;
    for (int v : a) {
        ans += v;
    }

    cout << ans << '\n';
}
