#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long sum(int idx) {
        long long res = 0;

        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }

        return res;
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

constexpr long long mod = 998244353;
long long pow_(long long a, long long b) {
    a %= mod;
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }

        b >>= 1;
        a = (a * a) % mod;
    }

    return ans % mod;
}

void solve() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // For each position ai and all bi we want to compute the number of ways we can have one or more smaller numbers before that number,
    // which is the definition of an inversion.
    //
    //
    // is it a Fenwick tree problem?
    // have a prefix Fenwick tree which will store pairs of type {score, coeff} and that will allow me to compute the total
    // number of positions and coefficients before some i that will have a value smaller than the number at position i with
    // some ci.
    //
    // but we can't handle overlaps this way, if some position j is counted with some coefficient bi then position j - 1
    // must take into account that and when it also uses that coefficient bi.

    //ordered_set<pair<long long, long long>> seen;
    //ordered_set<pair<long long, long long>> pref;
    //long long total = 0;

    //for (int i = 0; i < n; ++i) {
    //    long long inv = seen.size() - seen.order_of_key({ a[i], LLONG_MAX });
    //    seen.insert({ a[i], i });

    //    for (int l = 0; l < n; ++l) {
    //        long long cur = a[i] * b[l];
    //        long long greater = pref.size() - pref.order_of_key({ cur, LLONG_MAX });
    //        total = (total + greater) % mod;
    //    }
    //    total -= n * inv;

    //    for (int k = 0; k < n; ++k) {
    //        long long val = a[i] * b[k];
    //        pref.insert({ val, i * n + k });
    //    }
    //}

    //long long mult_inv = pow_(n * (n - 1), mod - 2);
    //total = (total * mult_inv) % mod;
    //cout << total << '\n';

    struct Frac {
        long long a;
        long long b;

        bool operator<(const Frac& other) const {
            return (__int128)a * other.b < (__int128)other.a * b;
        }
    };

    vector<Frac> coeff;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            coeff.push_back({ b[i], b[j] });
        }
    }
    sort(coeff.begin(), coeff.end());

    // aj * bk > ai * bl => aj / ai > bl / bk
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            Frac f = { a[j], a[i] };
            long long cnt = lower_bound(coeff.begin(), coeff.end(), f) - coeff.begin();

            total = (total + cnt) % mod;
        }
    }

    long long mult_inv = pow_(n * (n - 1), mod - 2);
    total = (total * mult_inv) % mod;
    cout << total << '\n';
}
