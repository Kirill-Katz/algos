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

    vector<int> vals(n);
    vector<int> type(n);

    for (int i = 0; i < n; ++i) {
        char c, v;
        cin >> c >> v;

        type[i] = c;
        vals[i] = v;
    }

    // Case 1:
    // Let's figure out what to do if we only have value of the type 's'.
    // if vals[i - 1] == vals[i] then for all j < i, p[j] < p[i].
    // vals[i] - vals[i - 1] tells us the number of numbers, p[j], s.t j < i and p[j] > p[i].
    //
    // If we have only type 's' we can solve the problem by starting at the end, as s[n - 1] - s[n - 2] will
    // tell us the number of numbers to the left of n - 1 which are greater than it and so we can recover that number.
    //
    // Case 2:
    // Doing vals[i] - vals[j] where i > j, we get the number of inversions with their R side being inside (j, i], call this value T.
    // Here we are guaranteed to have i - j > 1, otherwise we are in case 1. This means that the numbers in (j, i) are
    // known.
    //
    // vals[i] contains the total number of inversions we want to have at positions i.
    //
    // Call the set of all values which haven't been chosen yet U.
    //
    // There are 3 types of inversions:
    // 1. inversions in [0, j], which we don't care about, call it T1
    // 2. inversions in (j, i), i.e inversions totally inside (j, i), we don't care about these either, call them T2
    // 3. inversions with L in [0, j] and R in (j, i) which are computed in a special way: go through every value t3 in (j, i) and
    // compute the number of numbers u in U s.t u > t3.
    //
    // S = vals[i] - T1 - T2
    //
    // Every u has 3 values associated with it:
    // 1. M_u - the number of numbers in (j, i) > u
    // 2. G_u - the number of numbers in (j, i) < u
    // 3. H_u - the number of numbers in U > u
    //
    // And so our x in U must satisfy T1 + T2 + (T3 - G_x) + M_x + H_x = vals[i]
    //
    // Our T1 and T2 are fixed, so rewrite:
    //
    // T3 - G_x + M_x + H_x = vals[i] - T1 - T2
    //
    // We also know that M_x + G_x = |(j, i)|, so let L = |(j, i)|
    // we can rewrite the expression to be:
    //
    // T3 + L + H_x - 2G_x = vals[i] - T1 - T2
    //
    // So:
    //
    // H_x - 2G_x = vals[i] - T1 - T2 - T3 - L




}
