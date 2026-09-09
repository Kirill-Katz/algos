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
    string s;
    s.resize(n);

    // this is a block thing game.
    //
    // assume we have a 111001000 string that we perform only in order operations
    //
    // then we have the following configuration:
    // 3 -> -2
    // 1 -> -3
    // every operation decreases the number of inversions by the sum of values and decreases the top key by 1, like this:
    // 3 -> -2
    // 1 -> -3
    // -------
    // 2 -> -2
    // 1 -> -3
    // -------
    // 1 -> -2
    // 1 -> -3
    // ...
    //
    // Assume the full model with 2 operations. From 0s POV we have:
    // 3 -> -1
    // 2 -> -3
    // same thing: an operation decreases the top most key by 1.
    // so:
    // 2 -> -1
    // 2 -> -3
    // ------
    // 1 -> -1
    // 2 -> -3
    // ------
    // 0 -> -1
    // 2 -> -3
    // ....
    // BUT look what happens to the 1s table. Every 0 operation increases bottom most value by 1. For example:
    //
    // Assume before operations:
    // 1s:
    // 3 -> -2
    // 1 -> -3
    // 0s:
    // 3 -> -1
    // 2 -> -3
    //
    // Apply for 1 we get:
    // From: 111001000
    // To:   110010001
    // inversions = inversions - 5
    //
    // 1s:
    // 2 -> -2 # decrease key by 1
    // 1 -> -3
    //
    // 0s:
    // 3 -> -1
    // 2 -> -2 # increase val by 1
    // Each operation decreases the number of inversions by the sum of values for non zero keys, so we need to keep track of these values.

}
