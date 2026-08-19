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


long long _2D(vector<vector<int>>& mt, int n, int m, int k) {
    vector<long long> sum_col(m);
    vector<long long> sum_row(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum_row[i] += mt[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            sum_col[j] += mt[i][j];
        }
    }

    vector<long long> moves;
    moves.reserve(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long without_i_j = sum_col[j] + sum_row[i] - 2LL * mt[i][j];
            long long need = without_i_j - mt[i][j];

            long long mvs = (max(0LL, need) + n + m - 4) / (n + m - 3);

            moves.push_back(mvs);
        }
    }

    sort(moves.begin(), moves.end());

    return max(moves[k - 1], 0LL);
}

long long _1D(vector<vector<int>>& mt, int n, int m, int k) {
    // define h[i] = S - 2*a[i]
    // define L = r - l + 1
    //
    // we have  the function
    // f(l, r) =
    // 1. -L + 2, if h[i] in [l, r]
    // 2. -L, if h[i] outside [l, r]
    //
    // Wait, L + 2 is literally the same as L, because the inside elements when having L + 2 get the same impact as the
    // outside elements of L. So if the size of a is even we can just pick all the elements all the time, if a is odd then
    // there is no point in picking one "outskirt" element,

    long long sum = 0;
    vector<long long> a(max(n, m));
    auto normalize = [&]() {
        if (m == 1) {
            for (int i = 0; i < n; ++i) {
                a[i] = mt[i][0];
                sum += a[i];
            }
        } else if (n == 1) {
            for (int j = 0; j < m; ++j) {
                a[j] = mt[0][j];
                sum += a[j];
            }
        }
    };

    normalize();
    n = max(n, m);

    if (n == 2) {
        return (k == 2 ? max(a[0], a[1]) - min(a[1], a[0]) : 0);
    }


    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        h[i] = sum - 2 * a[i];
    }

    vector<pair<long long, int>> h_sorted(n);
    for (int i = 0; i < n; ++i) {
        h_sorted[i] = { h[i], i };
    }
    sort(h_sorted.begin(), h_sorted.end());

    vector<long long> moves(n);
    long long L = n;

    for (int i = 0; i < n; ++i) {
        if (h[i] <= 0) {
            moves[i] = 0LL;
        } else {
            if (L - 2 > 0) {
                moves[i] = (h[i] + L - 3) / (L - 2);
            } else {
                moves[i] = LLONG_MAX;
            }
        }
    }

    sort(moves.begin(), moves.end());
    long long T = moves[k - 1];

    if (k == 1) {
        long long only_first = (h[0] + n - 2) / (n - 1);
        long long only_last = (h[n - 1] + n - 2) / (n - 1);

        return max(0LL, min({ T, only_first, only_last }));
    }

    auto check = [&](int p) {
        long long q;

        if (h[p] <= h_sorted[k - 2].first) {
            q = h_sorted[k - 1].first;
        } else {
            q = h_sorted[k - 2].first;
        }

        // T * (n - 2) + y >= h[p] => y >= h[p] - T * (n - 2)
        //
        // T * (n - 2) - y >= h_t0 => y <= T * (n - 2) - h_0

        auto ok = [&] (long long T) {
            long long low = max(0LL, h[p] - T * (n - 2));
            long long high = min(T, T * (n - 2) - q);
            return low <= high;
        };

        long long l = 0, r = T;

        while (l < r) { // FFTT
            long long m = l + (r - l) / 2;

            if (ok(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    };

    return max(0LL, min({ T, check(0), check(n - 1) }));
}

void solve() {
    // assume we pick the whole grid in a single operation, then
    // for each cell its "peakness" increases by (n - 1) + (m - 1) - 1 which is
    // n - 1 + m - 1 - 1 = n + m - 3. So in a case when we have n > 2 and m > 2 it is
    // always optimal to pick the whole grid.
    //
    // The hard thing is the case when we have a single 1D line.
    //
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mt(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mt[i][j];
        }
    }

    if (n == 1 && m == 1) {
        if (mt[0][0] < 0) {
            cout << -1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    if (n >= 2 && m >= 2) {
        cout << _2D(mt, n, m, k) << '\n';
    } else {
        cout << _1D(mt, n, m, k) << '\n';
    }
}
