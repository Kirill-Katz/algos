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

    // [_____] 1 [_____] 1 [_____] 1 [______]
    //    x         y         z         w

    if (n == 1) {
        cout << "1" << '\n';
        return;
    }

    if (n == 2) {
        cout << "11" << '\n';
        return;
    }

    if (n == 3) {
        cout << "101" << '\n';
        return;
    }

    array<int, 2> a = { n / 3 - 1, n / 3 };
    array<int, 2> b = { 2 * n / 3 - 1, 2 * n / 3 };

    vector<string> cand;
    for (int i : a) {
        for (int j : b) {
            if (i < 0 || j < 0 || i >= j || j >= n) {
                continue;
            }

            string c(n, '0');
            c[i] = '1';
            c[j] = '1';

            cand.push_back(c);

            if (j != n - 1) {
                c[n - 1] = '1';
                cand.push_back(c);
            }
        }
    }

    auto good = [](const string& s) -> bool {
        array<int, 3> cnt = {1, 0, 0};
        int rem = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') {
                rem = (rem + (i % 2 == 0 ? 2 : 1)) % 3;
            }

            cnt[rem]++;
        }

        return *max_element(cnt.begin(), cnt.end()) - *min_element(cnt.begin(), cnt.end()) <= 1;
    };


    for (const string& c : cand) {
        if (good(c)) {
            cout << c << '\n';
            return;
        }
    }
}

