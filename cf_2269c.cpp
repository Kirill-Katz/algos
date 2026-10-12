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

    long long ans = 0;
    for (int i = k - 1; i < n - k + 1; ++i) {
        ans += a[i];
    }

    vector<int> rem;
    if (n >= (k - 1) * 2) {
        for (int i = 0; i < k - 1; ++i) {
            rem.push_back(a[i]);
        }
        for (int i = n - k + 1; i < n; ++i) {
            rem.push_back(a[i]);
        }
    } else {
        rem = std::move(a);
    }

    int l = k - 1;
    int r = rem.size() - k;

    while (l < (int)rem.size() && r >= 0) {
        ans += max(rem[l], rem[r]);
        l++;
        r--;
    }

    cout << ans << '\n';
}
