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
   // When T picks an initial path (a, b) J has to choose a path that is connected to this path
   // by some vertex c that is a part of the sequence of the path (a, b).
   //
   // It seems like if T picks some path (s, f) then for all vertices u in (s, f) all the vertices c that are directly connected to u
   // but aren't a part of (s, f) (are children of u outside the path) should form a subtree rooted at c that does not have any branches and the
   // total number of c should be even.
   //
   // Proof sketch:
   //
   // Assume we have the subtree rooted at c and b is the vertex inside the subtree where there is a branch, i.e the number of children of b is >= 3.
   //
   // There are 2 cases:
   // 1. There are an even number of branches excluding branch (c, b). In this case J can pick
   // the path (c, b) and there will be an even number of possible paths to pick, which results in J winning, because we have T picks path (s, f)
   // J picks path (u, c, ..., b), T pick one reaming path, J picks the last path (when there are 2 remaining paths, but WLOG this works
   // for any even number of paths).
   //
   // 2. The branch happens at vertex b and there are an odd number of branches excluding branch (c, b). In this case assume some ll is a leaf in one of
   // the branches. J can pick the path (u, c, ..., ll) which leads to an even number of paths being available. Thus we have:
   // T picks (s, f), J picks (u, c, ..., l1), T picks the reaming path (...., l2), J wins by picking path (..., l3).
   //
   //
   //
}
