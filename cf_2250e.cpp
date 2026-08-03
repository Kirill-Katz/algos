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
    // the amount of information that changes when a new position is picked is very small:
    // picking the next position only pops from the front and pushes to the back.
    //
    // we can imagine the process of checking every prefix as filling a binary array.
    // We go from left to right through each position and if arr[i-1] and arr[i+1] are false, then we got +1 block.
    //
    // what we want is in no point in time to have more than 2 blocks.
    //
    // we know that if we take a number from the front and place it to the back, because it is the last number when it is placed
    // there is either one single block or there are two blocks (either 01111 or 11011) so we don't really care about the number being placed
    // last.
    //
    // maybe we can think in terms of points in time? let's call the number we are working with i.
    // If when i is placed it creates a new block, then moving it to the back removes that block from that point in time.
    // But we now need to also check i-1 and i+1, if when i-1 is placed it has no neighbours, then the number of blocks in that point
    // in time should be increased, the same as with i+1, but because i-1 and i+1 have only 2 unique neighbours excluding our i, we
    // can probably check if i-2 and i+2 are placed before i, if so then i-1 and i+1 DO NOT introduce a new block when placed. We can
    // probably keep track of points in time when the number of blocks > 2, and when after moving i to the back we get 0, this position is
    // "good".
    //
    // 1 3 5 2 4
    //
    // 1. 1 0 0 0 0 -> 1 block
    // 2. 1 0 1 0 0 -> 2 blocks
    // 3. 1 0 1 0 1 -> 3 blocks
    // 4. 1 1 1 0 1 -> 2 blocks
    // 5. 1 1 1 1 1 -> 1 block
    //
    // 1 2 3 4 5
    // 1 4 2 5 3
    //
    // 1 2 3 4 5
    // 6 4 2 5 3
    //

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<bool> bin(n + 1);
    vector<int> history(n);
    vector<int> when(n + 1);

    history[0] = 1;
    bin[a[0]] = true;
    when[a[0]] = 0;

    for (int i = 1; i < n; ++i) {
        int left = a[i] > 1 && bin[a[i]-1];
        int right = a[i] < n && bin[a[i] + 1];

        history[i] = history[i-1];
        when[a[i]] = i;

        if (!left && !right) {
            history[i] += 1;
        } else if (left && right) {
            history[i] -= 1;
        }

        bin[a[i]] = true;
    }

    vector<long long> mx(4 * n);
    vector<long long> lazy(4 * n);

    auto fill = [&](auto&& self, int u, int l, int r) -> void {
        if (l == r) {
            mx[u] = history[l];
            return;
        }

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;

        int m = l + (r - l) / 2;

        self(self, left_u, l, m);
        self(self, right_u, m + 1, r);

        mx[u] = max(mx[left_u], mx[right_u]);
    };

    fill(fill, 0, 0, n - 1);

    auto apply = [&](int u, long long v) {
        mx[u] += v;
        lazy[u] += v;
    };

    auto push = [&](int u) {
        if (lazy[u] == 0) {
            return;
        }

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;

        apply(left_u, lazy[u]);
        apply(right_u, lazy[u]);

        lazy[u] = 0;
    };

    auto add = [&](auto&& self, int u, int l, int r, int ql, int qr, long long v) -> void {
        if (r < ql || qr < l) {
            return;
        }

        if (ql <= l && r <= qr) { // node range inside the range we want
            mx[u] += v;
            lazy[u] += v;
            return;
        }

        push(u); // if not apply lazy propagation to chidren

        int left_u = 2 * u + 1;
        int right_u = 2 * u + 2;
        int m = l + (r - l) / 2;

        // so that this has the correct values.
        self(self, left_u, l, m, ql, qr, v);
        self(self, right_u, m + 1, r, ql, qr, v);

        mx[u] = max(mx[left_u], mx[right_u]);
    };


    auto add_ring = [&](int l, int r, long long v) {
        if (l > r) return;

        l %= n;
        r %= n;

        if (l <= r) {
            add(add, 0, 0, n - 1, l, r, v);
        } else {
            add(add, 0, 0, n - 1, l, n - 1, v);
            add(add, 0, 0, n - 1, 0, r, v);
        }
    };

    int ans = 0;
    for (int p = 0; p < n; ++p) {
        auto forward_time = [&](int q) {
            return q < p ? q + n : q;
        };

        if (a[p] == 1 || a[p] == n) {
            int neightbour = a[p] == 1 ? 2 : n - 1;
            int t = forward_time(when[neightbour]);

            add_ring(p + 1, t - 1, -1);
        } else {
            int l_t = forward_time(when[a[p] - 1]);
            int r_t = forward_time(when[a[p] + 1]);

            int t1 = min(l_t, r_t);
            int t2 = max(l_t, r_t);

            add_ring(p + 1, t1 - 1, -1);
            add_ring(t2, p + n - 1, 1);
        }

        if (mx[0] <= 2) {
            ans++;
        }
    }

    cout << ans << '\n';
}
