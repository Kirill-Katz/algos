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
    int n, x;
    cin >> n >> x;

    // There are a few useful configurations:
    // 1. 0 y
    //    y x
    //
    // 2. a x
    //    x b where (a ^ b) = x
    //
    // 3. a y
    //    y b where (a ^ b) = x
    //
    // 4. a b
    //    c d where (a ^ b) ^ (c ^ d) = x
    //
    // 5. a b
    //    c x where (a ^ b ^ c) = 0
    //
    // So every possible 2 by 2 square in the matrix should have one of these configurations.
    //
    //
    // d_i(j) = A_i,j ^ A_i+1,j
    // d_i(j + 1) = A_i,j+1 ^ A_i+1,j+1
    //
    // So d_i(j) ^ d_i(j + 1) = x
    //
    // So d_i(j + 1) = d_i(j) ^ x
    //
    // d_i(j + 2) = d_i(j + 1) ^ x <=> d_i(j) ^ x ^ x => d_i(j + 2) = d_i(j)
    //
    // So the problem reduces to buiding a 2 by n matrix first, after that we will be able to cover the whole matrix wit this
    // 2 by n matrix, because row_i xor row_j == row_j xor row_i
    //
    // Ok, so now that we have both reductions what we want is a 2 by n matrix where the difference between m[i][0] and m[i][1] is the same as
    // the difference between m[i + 2][0] and m[i + 2][1], so note:
    //
    // m[i][0] xor m[i][1] = a where i is even
    // m[i+1][0] xor m[i+1][1] = b where i+1 is odd
    //
    // Wait, so we have (n - 1)^2 total pairs and what we want is to have at least ceil(n / 2) pairs out of (n - 1)^2 where their difference is a
    // and ceil(n / 2) pairs out of (n - 1)^2 to have their difference equal to b.
    //
    // No way this is gonna work.

    vector<int> cnt(4096);

    for (int i = 0; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n - 1; ++j) {
            cnt[i ^ j]++;
        }
    }

    vector<int> a;

    for (int a_cand = 0; a_cand < 4096; ++a_cand) {
        int b_cand = a_cand ^ x;

        if ((int)cnt[a_cand] >= (n + 1) / 2 && (int)cnt[b_cand] >= n / 2) {
            a.push_back(a_cand);
        }
    }

    if (a.size() < (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
        ans[0][j] = j;
    }

    int total = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = ans[i-1][j] ^ a[i-1];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
