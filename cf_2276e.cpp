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
    // use a window to find a 2025 containing substring, move l to the right to find the smallest
    // string that contains that subsequence that forms 2025.
    //
    // After that we need to find the position L, where L is the greatest index such that [L, r] doesn't contain
    // the subsequence 2026, and then we need to find R the index of the closest 6 to the right - 1, so [L, R] will contain
    // the 2025, but will not contains any fixing 2026. P.s we can find the L by binary searching using a seg tree in log^2(n).
    // P.s 2 we probably don't even need a seg tree, we can make a map my doing the same window thing but for 2026.
    //
    // Let's call [l, r] the core. Assume firstly that all the indices get the full set of all substrings, i.e we assume i can be
    // part of all substrings that contains it.
    //
    // This means that the "core" [l, r] will get a get a decrease of (l - L) * (R - r) (no -1 because we include the 0 case, i.e we pick
    // 0 elements from l and r) all the other elements in [l, L) and (r, R] will get a decrease of -1, because they are included once.
    //
    // We can do that with a lazy seg tree, but there is probably a better way with prefixes somehow idk.


}
