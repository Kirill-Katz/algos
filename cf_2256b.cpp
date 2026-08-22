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

constexpr long long mod = 998244353;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool odd_fixed = false;
    bool even_fixed = false;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (s[i] != '?') {
                even_fixed = true;
            }
        } else {
            if (s[i] != '?') {
                odd_fixed = true;
            }
        }
    }

    auto check = [&](bool even, char setc = '?') {
        string s_tmp = s;
        if (setc != '?') {
            s_tmp[!even] = setc;
        }

        bool is_zero = !(even ? s_tmp[0] == '0' : s_tmp[1] == '0');

        for (int i = !even; i < n; i += 2) {
            if ((is_zero && s_tmp[i] == '0') || (!is_zero && s_tmp[i] == '1')) {
                return false;
            } else {
                is_zero = !is_zero;
            }
        }

        return true;
    };

    if (even_fixed) {
        bool status = false;
        if (s[0] == '?') {
            status = check(true, '0') || check(true, '1');
        } else {
            status = check(true);
        }

        if (!status) {
            cout << 0 << '\n';
            return;
        }
    }


    if (odd_fixed) {
        bool status = false;
        if (s[1] == '?') {
            status = check(false, '0') || check(false, '1');
        } else {
            status = check(false);
        }

        if (!status) {
            cout << 0 << '\n';
            return;
        }
    }

    if (odd_fixed && even_fixed) {
        cout << 1 << '\n';
    } else if (odd_fixed || even_fixed) {
        cout << 2 << '\n';
    } else {
        cout << 4 << '\n';
    }
}
