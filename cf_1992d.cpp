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
    int n, m, k;
    // len, jump, swim
    cin >> n >> m >> k;

    string a;
    a.push_back('L');
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        a.push_back(c);
    }
    a.push_back('L');

    int cur_k = k;

    for (int i = 0; i < n + 1;) {
        int orig_i = i;

        bool swim = true;
        while (i + 1 <= min(n + 1, orig_i + m)) {
            i++;

            if (a[i] == 'L') {
                swim = false;
                break;
            }
        }

        while (swim && cur_k > 0) {
            if (a[i] == 'L') {
                break;
            }

            if (a[i] == 'C') {
                cout << "NO" << '\n';
                return;
            }

            cur_k--;
            i++;
        }

        if (a[i] != 'L') {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
