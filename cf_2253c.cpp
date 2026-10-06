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

    ranges::sort(a, greater<int>());
    ranges::sort(b, greater<int>());

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

    int a_left = n - 1;
    int b_left = m - 1;

    long long ans = 0;

    for (int i = 0; i < n + m - 2; ++i) {
        int a_only_el = INT_MIN;
        int b_only_el = INT_MIN;
        int both_el = INT_MIN;

        if (!a_only.empty()) {
            a_only_el = *a_only.rbegin();
        }
        if (!b_only.empty()) {
            b_only_el = *b_only.rbegin();
        }
        if (!both.empty()) {
            both_el = *both.rbegin();
        }

        if (a_left == 0) {
            if (b_only_el > both_el) {
                ans += b_only_el;
                b_only.erase(b_only_el);
            } else {
                ans += both_el;
                both.erase(both_el);
            }

            b_left--;
            continue;
        }

        if (b_left == 0) {
            if (a_only_el > both_el) {
                ans += a_only_el;
                a_only.erase(a_only_el);
            } else {
                ans += both_el;
                both.erase(both_el);
            }

            a_left--;
            continue;
        }

        if (a_only_el > max(both_el, b_only_el)) {
            ans += a_only_el;
            a_left--;
            a_only.erase(a_only_el);
            continue;
        }

        if (b_only_el > max(both_el, a_only_el)) {
            ans += b_only_el;
            b_left--;
            b_only.erase(b_only_el);
            continue;
        }

        if (both_el > max(b_only_el, a_only_el)) {
            ans += both_el;
            a_left > b_left ? --a_left : --b_left;
            both.erase(both_el);
            continue;
        }
    }

    ans += max({
        a_only.empty() ? 0 : *a_only.rbegin(),
        b_only.empty() ? 0 : *b_only.rbegin(),
        both.empty() ? 0 : *both.rbegin()
    });

    cout << ans << '\n';
}
