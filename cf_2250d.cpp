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

constexpr long long mod = 998244353;
void solve() {
    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    // The only correct form of array a is increasing then decreasing otherwise ans := 0
    // In the increasing half if a[i] != a[i-1] then a[i] becomes the new maximum of a[0..i]
    // Therfore, if a[i] < i + 1 (zero indexed) then ans := 0

    bool decreasing = false;
    int p = n - 1;

    for (int i = 1; i < n - 1; ++i) {
        if (a[i] < a[i-1] && !decreasing) {
            decreasing = true;
            p = i;
        }

        if (a[i-1] < a[i] && decreasing) {
            cout << 0 << '\n';
            return;
        }
    }

    unordered_set<int> used;
    for (int i = 0; i < p; ++i) {
        used.insert(a[i]);
    }

    for (int i = p; i < n - 1; ++i) {
        if (used.contains(a[i])) {
            cout << 0 << '\n';
            return;
        }
    }

    for (int x : a) {
        if (n == x) {
            cout << 0 << '\n';
            return;
        }
    }

    int l = 0;
    int r = n - 2;

    vector<int> merged;
    merged.reserve(n - 1);

    while (l < p && r >= p) {
        if (a[l] < a[r]) {
            merged.push_back(a[l++]);
        } else {
            merged.push_back(a[r--]);
        }
    }

    while (l < p) {
        merged.push_back(a[l++]);
    }

    while (r >= p) {
        merged.push_back(a[r--]);
    }

    long long ans = 1;

    for (int i = 0; i < n - 1; ++i) {
        if (i == 0 || merged[i-1] != merged[i]) {
            continue;
        }

        long long choises = merged[i] - i;

        if (choises <= 0) {
            ans = 0;
            break;
        }

        ans = ans * choises % mod;
    }

    ans = ans * 2 % mod;
    cout << ans << '\n';
}
