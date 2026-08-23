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

    string s; cin >> s;

    int ones = 0;
    int zeros = 0;

    for (int i = 0; i < n; ++i) {
        ones += s[i] == '1';
        zeros += s[i] == '0';
    }

    if (abs(zeros - ones) > 2) {
        cout << -1 << '\n';
        return;
    }

    int a_ones = 0;
    int a_zeros = 0;

    for (int i = 0; i < n;) {
        int cur = s[i];
        int j = i;
        int count = 0;

        while (j < n && s[j] == cur) {
            count++;
            j++;
        }

        if (cur == '1') a_ones += count - 1;
        else a_zeros += count - 1;

        i = j;
    }

    if (a_zeros == a_ones) {
        cout << a_zeros + a_ones << '\n';
        return;
    }

    int remove = min(a_ones, a_zeros);
    int ans = remove * 2;

    a_ones -= remove;
    a_zeros -= remove;

    int rem = max(a_ones, a_zeros);

    if (rem == 1) {
        cout << ans + 1 << '\n';
    } else if (rem == 2) {
        cout << ans + 3 << '\n';
    } else if (rem == 3) {
        cout << ans + 5 << '\n';
    } else {
        cout << "shouldn't happen" << '\n';
    }
}
