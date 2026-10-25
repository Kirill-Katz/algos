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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ranges::sort(a);

    vector<pair<int,int>> b;
    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && a[i] == a[j]) {
            j++;
        }

        b.push_back({ a[i], j - i });
        i = j;
    }

    int need = 0;
    int additional = 0;

    for (auto [v, c] : b) {
        if (need == v && c + additional >= k) {
            need++;
            additional = c + additional - k;
        } else break;
    }

    cout << need << '\n';
}
