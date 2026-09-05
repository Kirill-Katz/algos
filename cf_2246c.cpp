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

constexpr long long mod = 1e9 + 7;

long long pow_(long long a, long long b) {
    a %= mod;

    long long temp = a;
    long long ans = 1;

    while (b > 0) {
        if (b & 1) {
            ans = ans * temp % mod;
        }

        temp = temp * temp % mod;
        b >>= 1;
    }

    return ans;
};

void solve() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 1. We can count the number of ways to pick an even number of elements in each block of numbers
    // 2. We can pick single adjacent numbers then their difference will be exactly -1

    unordered_map<long long,long long> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    long long d = 0;
    for (auto [_, __] : cnt) {
        d++;
    }

    long long l = 0;
    for (auto [v, c] : cnt) {
        if (v >= 1 && cnt.find(v + 1) != cnt.end()) {
            l++;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n - d; ++i) {
        ans = ans * 2 % mod;
    }

    if (cnt[-1] > 0) {
        ans = ans * (l + 1) % mod;
    }

    cout << ans << '\n';
}
