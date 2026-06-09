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

    string a;
    cin >> a;

    string b;
    cin >> b;


    // so the only numbers that are possible to achieve are a, b and c where c = a xor b.
    // so we only need to count the number of as, bs and cs we will get in our final array.

    // if we know that we have something like a....c....b then from the perspective of a....c we
    // know that we will get a b, but then this also tells us that on the other side we will be getting an a
    // in the middle.

    string c;
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        c[i] = a[i] == b[i] ? '0' : '1';
    }

    array<vector<long long>, 3> dp;
    dp.fill(vector<long long>(k + 1));

    dp[0][1] = 1; //cnt of a
    dp[1][1] = 1; //cnt of b
    dp[2][1] = 1; //cnt of c

    for (int i = 2; i <= k; ++i) {
        dp[0][i] = dp[0][i - 1] + dp[2][i - 1];
        dp[1][i] = dp[1][i - 1] + dp[2][i - 1];
        dp[2][i] = dp[0][i - 1] + dp[1][i - 1] - 1;

        //cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << '\n';
    }

    long long ones_a = 0;
    long long ones_b = 0;
    long long ones_c = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') ones_a++;
        if (b[i] == '1') ones_b++;
        if (c[i] == '1') ones_c++;
    }

    long long ans =
        (n - ones_a) * ones_a * dp[0][k] +
        (n - ones_b) * ones_b * dp[1][k] +
        (n - ones_c) * ones_c * dp[2][k];


    cout << ans << '\n';
}
