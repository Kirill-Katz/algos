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

    vector<long long> vals(n);
    vector<char> type(n);

    for (int i = 0; i < n; ++i) {
        cin >> type[i];
        cin >> vals[i];
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
    // Call the set of all values which haven't been chosen OR which we haven't seen yet U.
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

    auto change = [](auto& seg, int p, int v) {
        int n = (int)seg.size() / 2;
        p += n;

        int delta = v - seg[p];
        seg[p] = v;

        while (p > 1) {
            p /= 2;
            seg[p] += delta;
        }
    };

    auto get = [](auto& seg, int l, int r) {
        int res = 0;
        int n = seg.size() / 2;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res += seg[l++];
            }
            if (r & 1) {
                res += seg[--r];
            }
        }

        return res;
    };

    auto kth = [get](auto& seg, int val) {
        int n = seg.size() / 2;
        int p = 1;

        while (p < n) {
            int left = 2 * p;

            if (val < seg[left]) {
                p = left;
            } else {
                val -= seg[left];
                p = left + 1;
            }
        }

        return p - n;
    };

    auto size_ = [](auto& seg) {
        return seg[1];
    };

    int sz = 1;
    while (sz < n) {
        sz <<= 1;
    }

    vector<int> U(2*sz);

    for (int i = 0; i < n; ++i) {
        U[sz + i] = 1;
    }

    for (int i = sz - 1; i >= 1; --i) {
        U[i] = U[2 * i] + U[2 * i + 1];
    }

    auto case_1 = [&](int i) {
        int greater = vals[i] - vals[i - 1];
        int pos = kth(U, size_(U) - greater - 1);
        change(U, pos, 0);
        return pos + 1;
    };

    vector<int> seg(2*n);

    auto case_2 = [&](int i) {
        int j = i - 1;

        vector<int> p_block;

        while (j >= 0 && type[j] == 'p') {
            int x = (int)vals[j] - 1;
            p_block.push_back(x);
            change(U, x, 0);
            j--;
        }

        if (j == -1) {
            return kth(U, 0) + 1;
        }

        std::reverse(p_block.begin(), p_block.end());
        long long S = vals[i];
        long long T1 = vals[j];
        long long T2 = 0;
        long long T3 = 0;
        long long L = (int)p_block.size();

        for (int p_i : p_block) {
            T2 += get(seg, p_i + 1, n);
            T3 += get(U, p_i + 1, n);
            change(seg, p_i, 1);
        }

        // H_x - 2*G_x = S - T1 - T2 - T3 - L
        long long target = S - T1 - T2 - T3 - L;

        int l = 0;
        int r = size_(U) - 1;

        auto value = [&](int x) {
            // G_u - the number of numbers in (j, i) < u
            // H_u - the number of numbers in U > u
            long long G_u = get(seg, 0, x);
            long long H_u = get(U, x + 1, n);
            return H_u - 2*G_u;
        };

        while (l < r) {
            int m = l + (r - l) / 2;
            int x = kth(U, m);

            if (value(x) <= target) { // FFFTTT
                r = m;
            } else {
                l = m + 1;
            }
        }

        int x = kth(U, l);
        assert(value(x) == target);

        change(U, x, 0);
        for (int x : p_block) {
            change(seg, x, 0);
        }

        return x + 1;
    };

    vector<int> ans(n);

    for (int i = n - 1; i >= 1; --i) {
        if (type[i] == 's' && type[i - 1] == 's') {
            ans[i] = case_1(i);
        } else if (type[i] == 'p') {
            ans[i] = vals[i];
            change(U, vals[i] - 1, 0);
        } else if (type[i] == 's' && type[i - 1] == 'p') {
            ans[i] = case_2(i);
        }
    }

    if (type[0] == 's') {
        ans[0] = kth(U, 0) + 1;
    } else {
        ans[0] = vals[0];
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
