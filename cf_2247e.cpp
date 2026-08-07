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
    // can be simplified to n^2 / 2
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
    // can be smplified to (n^2 - 1) / 2


    // cout << "inc: " << '\n';

    // cout << score({1, 2, 3, 4, 5, 6, 7, 8}) << '\n';
    // cout << score({1, 3, 2, 4, 5, 6, 7, 8}) << '\n';
    // cout << score({1, 3, 2, 5, 4, 6, 7, 8}) << '\n';
    // cout << score({1, 3, 2, 5, 4, 7, 6, 8}) << '\n';
    // // cout << score({1, 5, 3, 4, 2, 6, 7, 8}) << '\n';
    // // cout << score({1, 5, 3, 4, 2, 7, 6, 8}) << '\n';

    // // cout << score({1, 6, 3, 4, 5, 2, 7, 8}) << '\n';

    // cout << "dec: " << '\n';

    // cout << score({1, 3, 5, 7, 2, 4, 6, 8}) << '\n';
    // cout << score({7, 3, 5, 2, 1, 4, 6, 8}) << '\n';

    // cout << score({5, 7, 4, 2, 1, 3, 6, 8}) << '\n';
    // cout << score({7, 6, 4, 2, 1, 3, 5, 8}) << '\n';

    // cout << score({5, 4, 7, 2, 1, 6, 3, 8}) << '\n';

    // cout << score({5, 4, 2, 7, 6, 1, 3, 8}) << '\n';
    // cout << score({5, 4, 2, 6, 7, 1, 3, 8}) << '\n';

    // auto score = [&](vector<int>&& a) {
    //     int n = a.size();
    //     vector<int> pos(n + 1);

    //     for (int i = 0; i < n; ++i) {
    //         pos[a[i]] = i;
    //     }

    //     int ans = 0;

    //     for (int i = 1; i < n; ++i) {
    //         ans += abs(pos[i] - pos[i + 1]);
    //     }

    //     ans += abs(pos[n] - pos[1]);

    //     return ans;
    // };

    // cout << "\n\n";
    // cout << score({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 2, 5, 6, 7, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 2, 6, 7, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 2, 7, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 7, 2, 8, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 7, 8, 2, 9, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 7, 8, 9, 2, 10, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 7, 8, 9, 10, 2, 11, 12}) << '\n';
    // cout << score({1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 12}) << '\n';

    // cout << score({1, 3, 5, 4, 6, 7, 8, 9, 10, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 4, 7, 8, 9, 10, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 7, 4, 8, 9, 10, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 7, 8, 4, 9, 10, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 7, 8, 9, 4, 10, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 7, 8, 9, 10, 4, 11, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 6, 7, 8, 9, 10, 11, 4, 2, 12}) << '\n';

    // cout << score({1, 3, 5, 7, 6, 8, 9, 10, 11, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 8, 6, 9, 10, 11, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 8, 9, 6, 10, 11, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 8, 9, 10, 6, 11, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 8, 9, 10, 11, 6, 4, 2, 12}) << '\n';

    // cout << score({1, 3, 5, 7, 9, 8, 10, 11, 6, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 9, 10, 8, 11, 6, 4, 2, 12}) << '\n';
    // cout << score({1, 3, 5, 7, 9, 10, 11, 8, 6, 4, 2, 12}) << '\n';

    // cout << score({1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2, 12}) << '\n';
    // I can't fucking believe it. This is it. This is the transition.

    // Ok, now we can think in terms of moves.
    //
    // the minimum is 2n - 2 so normalize k: m = (k - (2n - 2)) / 2 = k / 2 - n + 1
    // this gives us the exact move number in our transition.
    //
    // 2 will make n - 3 swaps, i.e [1, n - 2) moves
    // 4 can make n - 5 swaps, i.e n - 2 + n - 5 = 2n - 7 so [n - 2, 2n - 7)
    // 6 can make n - 7 swaps, i.e 2n - 7 + n - 7 = 3n - 14 so [2n - 7, 3n - 14)
    //
    //

    long long n, k;
    cin >> n >> k;

    long long min_v = 2 * n - 2;
    long long max_v = 0;
    if (n % 2) {
        max_v = (n - 1) * (2 + (n - 1)) / 2;
    } else {
        max_v = n + (n - 2) / 2 * n;
    }

    if (k < min_v || k > max_v || k % 2) {
        cout << -1 << '\n';
        return;
    }

    long long m = k / 2 - n + 1;
    if (m == 0) {
        for (int i = 1; i < n; ++i) {
            cout << i << ' ' << i + 1 << '\n';
        }
        return;
    }

    list<int> ans(n);
    std::iota(ans.begin(), ans.end(), 1);

    long long l = 1;
    long long r = n - 2;
    long long swaps = n - 5;

    auto it_left = next(ans.begin());
    auto it_right = prev(ans.end());

    while (m >= r) {
        l = r;
        r += swaps;
        swaps -= 2;

        auto next_it = next(next(it_left));
        ans.splice(it_right, ans, it_left);

        it_right = it_left;
        it_left = next_it;
    }

    long long t = m - l;
    ans.splice(next(it_left, t + 2), ans, it_left);

    for (auto it = ans.begin(); next(it) != ans.end(); it++) {
        cout << *it << ' ' << *next(it) << '\n';
    }
}
