#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(vector<long long>& primes);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    vector<bool> is_prime(1e5+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= 1e5; ++i) {
        if (is_prime[i]) {
            for (int j = i + i; j <= 1e5; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<long long> primes;
    primes.reserve(9592);

    for (int i = 0; i <= 1e5; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    while (t--) solve(primes);

    return 0;
}

void solve(vector<long long>& primes) {
    int n;
    cin >> n;

    // dumb O(n^2) idea:
    // take p1 to be a prime number, then for all p2 check (p1 + p2 + i - 1) / i if it is a prime number, if it is
    // add it.
    //
    // ((p1) + p2 + i - 1) / i = c2 => p1 + p2 + i - 1 = c2 * i => p2 = c2 * i - (p1) - i + 1
    //
    // there are 9592 primes <= 1e5, 1e5 * 9e3 = 9e8 which is not feasible
    // wait, but I need only at most 1e5 / 3 - 1 primes, so we have 33332 * 9592

    // p - 1 >= n / 3 - 1
    // p >= ceil(n / 3)
    // and n - p >= n / 3 - 1
    // p <= 2n / 3

    int left = (n + 2) / 3;
    // right = (2*n) / 3
    // by the Bertrad's posulate there will always be a prime between [x, 2*x] which is exactly [left, right] and because
    // there are exactly n / 3 numbers to the left of left and n / 3 number to the right of (2*n) / 3 we can always achieve
    // the average i.e sum / i = p where p is the prime we choose originally.

    int p = *lower_bound(primes.begin(), primes.end(), left);

    vector<int> ans;
    vector<bool> used(n + 1, false);

    ans.push_back(p);
    used[p] = true;

    for (int d = 1; (int)ans.size() < n / 3; ++d) {
        if (p - d >= 1 && !used[p - d]) {
            ans.push_back(p - d);
            used[p - d] = true;
        }

        if ((int) ans.size() < n / 3 && p + d <= n && !used[p + d]) {
            ans.push_back(p + d);
            used[p + d] = true;
        }
    }

    for (int x = 1; x <= n; ++x) {
        if (!used[x]) {
            ans.push_back(x);
        }
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
