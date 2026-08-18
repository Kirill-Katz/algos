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

            long long mvs = (max(0LL, need) + n + m - 2) / (n + m - 3);

            moves.push_back(mvs);
        }
    }

    sort(moves.begin(), moves.end());

    return max(moves[k - 1], 0LL);
}

long long _1D(vector<vector<int>>& mt, int n, int m, int k) {
    //

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

    if (n >= 2 && m >= 2) {
        cout << _2D(mt, n, m, k) << '\n';
    } else {
        cout << _1D(mt, n, m, k) << '\n';
    }

}
