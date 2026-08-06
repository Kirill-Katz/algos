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
    long long n, k;
    cin >> n >> k;

    // It is easy to see that the minimum is 2n - 2
    //
    // The maximum is real hard though.
    //
    // We can look from the POV of a single edge. That edge will contribute exactly n when there are an even
    // number of nodes to its left and an even number of nodes to its right AND all the nodes from the left have
    // to cross it to get to the nodes to the right.
    //
    // Assume we have an even number of nodes for now, and place all the nodes in a line.
    // We can place the nodes in a such a way that all odd nodes will be on the left and all even nodes
    // to the right, thus this edge will be crossed n times. The next edge to the left and to the right
    // will be crossed 2*(n / 2 - 1) = n - 2 times, because we loose the "in and out" for a node when we do that.
    //
    // For n even:
    //
    // e = n - 1
    //
    // number of edges on the left and right = (e - 1) / 2
    // maximum edge on the left/right = (n - 2)
    // minimum edge on the left/right = (n - e + 1) = 2
    //
    // maximum score = n (from center) + ((e - 1) / 2 * (n - 2 + 2) / 2) * 2 (from both sides) = n + (e - 1) / 2 * n
    //
    // For n odd:
    //
    // e = n - 1 which is an even number
    //
    // edges on each side = e / 2
    // each side of the form:
    // 2, 4, ..., n - 3, n - 1
    //
    // 2 * ((n - 1) / 2 * (2 + (n - 1)) / 2)
    //

    long long min_v = 2 * n - 2;
    long long max_v = 0;
    if (n % 2) {
        max_v = (n - 1) * (2 + (n - 1)) / 2;
    } else {
        max_v = n + (n - 2) / 2 * n;
    }

    if (k < min_v || k > max_v || (min_v % 2 != k % 2)) {
        cout << -1 << '\n';
        return;
    }



}
