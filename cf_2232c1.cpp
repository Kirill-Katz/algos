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
    int n, x, s;
    cin >> n >> x >> s;

    string u;
    cin >> u;

    // 5 + 2 + 6 + 1 = 7 + 7 = 14 (

    int i = 0;
    int e = 0;
    int a = 0;

    for (char c : u) {
        i += (c == 'I');
        e += (c == 'E');
        a += (c == 'A');
    }

    auto check = [&](int v) {
        int ans = 0;
        int tables = x;
        long long ext_cap = 0;
        int skip = v;

        for (char c : u) {
            if (c == 'I') {
                if (tables > 0) {
                    ans++;
                    ext_cap += s - 1;
                    tables--;
                }
            } else if (c == 'E') {
                if (ext_cap > 0) {
                    ext_cap--;
                    ans++;
                }
            } else if (c == 'A') {
                if (skip > 0) {
                    if (tables > 0) {
                        ans++;
                        ext_cap += s - 1;
                        tables--;
                    }
                    skip--;
                } else {
                    if (ext_cap > 0) {
                        ext_cap--;
                        ans++;
                    }
                }
            }
        }

        return ans;
    };

    int l = 0, r = a;

    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (check(m - 1) <= check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << check(l) << '\n';
}
