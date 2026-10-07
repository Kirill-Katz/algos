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
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(x);
    vector<int> b(y);

    set<int> a_set;
    for (int i = 0; i < x; ++i) {
        cin >> a[i];
        a_set.insert(a[i]);
    }

    set<int> b_set;
    for (int i = 0; i < y; ++i) {
        cin >> b[i];
        b_set.insert(b[i]);
    }

    set<int> a_only;
    set<int> b_only;
    set<int> both;

    for (int va : a) {
        if (b_set.contains(va)) {
            both.insert(va);
        } else {
            a_only.insert(va);
        }
    }

    for (int vb : b) {
        if (a_set.contains(vb)) {
            both.insert(vb);
        } else {
            b_only.insert(vb);
        }
    }

    long long ans = 0;

    int a_used = 0;
    int b_used = 0;
    int need = n + m - 1;

    for (;;) {
        if (need == 0) {
            break;
        }

        bool can_a = !a_only.empty() && a_used < n;
        bool can_b = !b_only.empty() && b_used < m;
        bool can_both = !both.empty();

        int av = can_a ? *a_only.rbegin() : INT_MIN;
        int bv = can_b ? *b_only.rbegin() : INT_MIN;
        int cv = can_both ? *both.rbegin() : INT_MIN;

        int best = max({av, bv, cv});

        if (best == INT_MIN) {
            break;
        }

        ans += best;
        need--;

        if (best == cv) {
            both.erase(cv);
        } else if (best == av) {
            a_only.erase(av);
            a_used++;
        } else {
            b_only.erase(bv);
            b_used++;
        }
    }

    cout << ans << '\n';
}
