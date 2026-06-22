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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // reverse LIS?


    vector<int> parent(n, -1);
    vector<int> tail;
    vector<int> tail_idx;

    for (int i = 0; i < n; ++i) {
        int x = -a[i];

        int pos = lower_bound(tail.begin(), tail.end(), x) - tail.begin();

        if (pos == (int)tail.size()) {
            tail.push_back(x);
            tail_idx.push_back(i);
        } else {
            tail[pos] = x;
            tail_idx[pos] = i;
        }

        if (pos > 0) {
            parent[i] = tail_idx[pos - 1];
        }
    }

    vector<int> seq;
    int cur = tail_idx.back();

    while (cur != -1) {
        seq.push_back(cur);
        cur = parent[cur];
    }

    reverse(seq.begin(), seq.end());

    vector<int> rem;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < (int)seq.size() && i == seq[j]) {
            j++;
        } else {
            rem.push_back(a[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)rem.size() - 1; ++i) {
        if (rem[i] < rem[i + 1]) {
            ans++;
        }
    }

    cout << ans << '\n';
}
