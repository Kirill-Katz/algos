#include <algorithm>
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the minimum value we can achieve is max(a) * n

    sort(a.begin(), a.end());

    long long max_v = *std::max_element(a.begin(), a.end());
    long long mex = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mex) {
            mex++;
        }
    }

    // sum from 0 to mex - 1 = (mex - 1) * mex / 2

    long long mex_sum = 0;

    if (mex == max_v + 1) {
        mex_sum = (mex - 1) * (mex - 2) / 2 + mex * (n - mex + 1);
    } else {
        mex_sum = mex * (mex + 1) / 2 + mex * (n - mex - 1);
    }

    cout << mex_sum + max_v * n << '\n';
}
