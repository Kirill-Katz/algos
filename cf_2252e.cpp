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
void solve() {
    long long n;
    cin >> n;

    // if a ^ b ^ c = 0 then
    // 1. (a ^ b) = c
    // 2. (a ^ c) = b
    // 3. (c ^ b) = a
    //
    // so a ^ b = c for b - a = c - b
    //
    // b - a = c - b => c = 2b - a
    //
    // a ^ b = 2b - a, b > a
    //
    // a ^ (a + k) = a + 2k, a + 2k < n
    //
    // a = 01000
    // b = 10000
    // c = 11000
    //
    // the 2 bit sections: 11, 01, 10 seem promissing. They look like the smallest building
    // block of a valid triplet (a, b, c)
    //
    // So a ^ b = c must be equivalent to b + (a - b) = c
    //
    // So the first two bits of a, b and c (from the left) are always:
    // 01
    // 10
    // 11
    //
    // the next two bits can be either:
    // 0
    // 0
    // 0
    // or
    // 01
    // 10
    // 11
    // or
    // 11
    // 10
    // 01
    // and so on, so a valid config is always a combo of these 3 type of blocks.
    // We can probably use some kind of DP to count the total count of these bits.
    // for (int i = 1; i <= 63; ++i) {
    //     for (int k = 1; k <= 63; ++k) {
    //         if (i + 2*k <= 63) {
    //             int a = i;
    //             int b = i + k;
    //             int c = i + 2*k;
    //             if ((a ^ b) == c) {
    //                 cout << bitset<32>(a) << '\n'
    //                      << bitset<32>(b) << '\n'
    //                      << bitset<32>(c) << "\n\n";
    //             }
    //         }
    //     }
    // }

    auto count = [&](int bits) -> long long {
        assert(bits >= 0 && bits < 64);

        vector<long long>dp(bits + 1);

        dp[0] = 1;

        if (bits >= 1) {
            dp[1] = 1;
        }

        for (int i = 2; i <= bits; ++i) {
            dp[i] = (dp[i-1] + (2 * dp[i-2] % mod)) % mod;
        }

        return dp[bits];
    };

    int bits = 64 - __builtin_clzll(n);
    long long ans = 0;

    for (int b = 2; b < bits; ++b) {
        ans = (count(b - 2) + ans) % mod;
    }

    auto prefix = [&](auto&& self, int b) -> long long {
        if (b <= 0) return 1;

        long long local = 0;

        bool is_0 = ((n >> b) & 0b1) == 0;
        bool is_01 = b >= 1 && (((n >> (b - 1)) & 0b11) == 0b01);
        bool is_11 = b >= 1 && (((n >> (b - 1)) & 0b11) == 0b11);

        if (is_01) {
            local = (local + self(self, b - 1)) % mod;
            local = (local + self(self, b - 2)) % mod;
        } else if (is_0) {
            local = (local + self(self, b - 1)) % mod;
        } else if (is_11) {
            local = (local + count(b)) % mod;
            local = (local + count(b - 1)) % mod;
            local = (local + self(self, b - 2)) % mod;
        } else {
            local = (local + count(b)) % mod;
            local = (local + count(b - 1)) % mod;
        }

        return local;
    };

    if (((n >> (bits - 2)) & 0b11) == 0b11) {
        ans = (ans + prefix(prefix, bits - 3)) % mod;
    }

    cout << ans << '\n';
}
