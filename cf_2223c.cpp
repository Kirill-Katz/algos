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
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int u = 2; u <= n - 1; ++u) {
        cin >> p[u];
    }

    vector<int> t(n);
    for (int u = 2; u <= n - 1; ++u) {
        cin >> t[u];
    }

    vector<int> m(q);
    for (int i = 0; i < q; ++i) {
        cin >> m[i];
    }

    // so all the signposts change in "sync", for each node u its signpost changes every second.
    // maybe the end result depends on m[i] % some number, and my goal is to determine that number?
    //
    // first of all can we simplify the "weights"? we probably can by going though the tree and for each node
    // u assume l_u = t, then the "default" child node of node u will be t mod d_u + 1, which allows us to set
    // all the position to a default configuration, and to ignore the weights from now on.
    //
    // now that we "normalized" the tree we can go for each node and do something like:
    // for node 1 check all its children, for child 0 to be chosen m must be divisible by d_1 (the number of children of node 1)
    // for node 1 to be chosen m - 1 must be divisible by d_1, etc. Then for each node go to the next level in BFS fashion and
    // get a map of "divisibility" on the number m, after that when a number m is queried we can check: what numbers is number m
    // divisible by.
    //
    // so assume we have a tree of where the root is connected to 4 other nodes and node 1 is connected to 3 leaves.
    //         0
    //      0 1 2 3
    //    0 1 2
    //
    //  here I use 0, 1 2 to note modulo groups. Basically if the number of children in a subtree is n, and the number of children in
    //  the subtree above is m,then if gcd(n, m) = 1, we will need CRT, otherwise they will be "synchronized" in other words the
    //  result will depend on the mod max(n, m).
    //
    //  Maybe we can somehow use CRT to find that magic "some number" I mentioned in the start?
    //
    //




}
