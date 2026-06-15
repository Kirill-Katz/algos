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
    string a;
    string b;

    cin >> n >> a >> b;

    // so there are 3 types or columns:
    // 1. a[i] and b[i] are closing
    // 2. a[i] and b[i] are opening
    // 3. a[i] and b[i] are different
    // first two types are fixed and cannot be  changed.

    int diff = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    // assume a is regular, then if b is different from a in one exact place then b cannot be regular
    // because b[i] == a[i] for all i except in that point where a[i] != b[i].
    if (diff % 2 != 0) {
        cout << "NO" << '\n';
        return;
    }


    int seen = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }

        ++seen;

        if (seen % 2 == 0) {
            a[i] = '(';
            b[i] = ')';
        } else {
            a[i] = ')';
            b[i] = '(';
        }
    }

    auto check = [&](const string& s) {
        int bal = 0;
        for (char c : s) {
            bal += c == '(' ? 1 : -1;

            if (bal < 0) {
                return false;
            }
        }
        return bal == 0;
    };

    cout << (check(a) && check(b) ? "YES" : "NO") << '\n';
}
