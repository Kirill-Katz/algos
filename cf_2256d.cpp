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

constexpr long long mod = 998'244'353;

long long pow_(long long a, long long b) {
    a %= mod;

    long long ans = 1;
    long long temp = a;

    while (b > 0) {
        if (b & 1) {
            ans = (ans * temp) % mod;
        }

        temp = (temp * temp) % mod;
        b >>= 1;
    }

    return ans;
}

long long inv(long long a) {
    return pow_(a, mod - 2);
}

long long fac(long long a) {
    long long ans = 1;
    for (int f = 1; f <= a; ++f) {
        ans = (ans * f) % mod;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // 11 and 00 are imporant, because
    // 01 pairs with 00 on the left, 11 on the right
    // 10 pairs with 11 on the left, 00 on the right

    // n - 1 + k choose k, where n is the number of 1 blocks
    // each block must have at least one digit so
    // n - 1 + (k - n) choose k = k - 1 choose k - n
    //
    // z - number of zeros
    // o - number of ones
    // zb - number of zero blocks
    // ob - number of one blocks
    //
    // (zb - 1 + (z - zb)) choose (z - zb) * (ob - 1 + (o + ob)) choose (o - ob)
    //
    // (z - 1 choose z - zb) * (o - 1 choose o - ob)

    long long z = 0;
    long long o = 0;

    long long zb = 0;
    long long ob = 0;

    for (int i = 0; i < n;) {
        char c = s[i];

        long long* vc = s[i] == '0' ? &z : &o;
        long long* bc = s[i] == '0' ? &zb : &ob;

        int j = i;
        while (j < n && s[j] == c) {
            (*vc)++;
            j++;
        }

        (*bc)++;
        i = j;
    }

    long long z_part = fac(z - 1) * (inv(fac(z - zb)) * inv(fac(zb - 1)) % mod) % mod;
    long long o_part = fac(o - 1) * (inv(fac(o - ob)) * inv(fac(ob - 1)) % mod) % mod;

    cout << (z_part * o_part) % mod << '\n';
}
