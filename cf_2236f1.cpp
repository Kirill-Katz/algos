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
    int n, x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // I don't even need to think in terms of divisors of a[i], I can think only about its prime factorization
    // So for each a[i] I need to pick a set of its prime factors such that those prime factors are unique in the
    // array. But a catch is the number 1, because it is not a prime, and can be used as a placeholder, because 1 * p[i] = p[i]
    // and 1 is a divisor of all a[i].
    //
    // Let's try to view each a[i] as a set of its prime factors. For each a[i] there are 2^p ways to pick a subset of its primes
    // (notice that we count 1 as an "empty set").
    //
    // There are very few unique prime factors maybe that's an optimization?
    //
    // Maybe there is a way to just do 2^p1 * 2^p2 / (number overlapping sets) somehow? where p1 and p2 are the number
    // of prime factors.
    //

    vector<unordered_map<long long, long long>> prime_factorization(n);

    for (int i = 0; i < n; ++i) {
        long long val = a[i];
        unordered_map<long long, long long> prime_factors;

        if (val % 2 == 0) {
            while (val % 2 == 0) {
                prime_factors[2]++;
                val /= 2;
            }
        }

        for (long long d = 3; d * d <= val; d += 2) {
            if (val % d == 0) {
                while(val % d == 0) {
                    prime_factors[d]++;
                    val /= d;
                }
            }
        }

        if (val > 1) {
            prime_factors[val]++;
        }

        prime_factorization[i] = std::move(prime_factors);
    }

    unordered_map<long long, long long> cnt;

    long long ans = 1;
    for (const auto& s : prime_factorization) {
        for (const auto& [k, v] : s) {
            cnt[k] += v;
        }
    }

    for (auto& [k, v] : cnt) {
        ans = ans * (v + 1) % mod;
    }

    cout << ans << '\n';
}
