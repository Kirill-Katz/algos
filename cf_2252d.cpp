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

    long long t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {


    // assum ai-1 and ai+1 are even, then
    // ai-1 + ai+1 is even
    // assume ai-1 and ai+1 are odd, then
    // ai-1 + ai+1 is even
    //
    // assume ai is odd,
    // then even - odd = odd
    // assume ai is even
    // then even - even = even.
    //
    // Thus the parity of ai stays the same
    //
    // Because parities can't change the whole array is split long longo blocks
    // of odd and even parities that do not influence each other
    //

    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> d(n - 1);
    for (long long i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }

    auto parity = [](long long x) {
        return ((x % 2) + 2) % 2;
    };

    for (long long i = 0; i < n - 1;) {
        long long j = i;

        while (j < n - 1 && parity(d[i]) == parity(d[j])) {
            ++j;
        }

        ranges::sort(d.begin() + i, d.begin() + j);
        i = j;
    }

    vector<long long> ans(n);
    ans[0] = a[0];

    for (long long i = 0; i < n - 1; ++i) {
        ans[i + 1] = 1LL * ans[i] + 1LL * d[i];
    }

    for (long long v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
