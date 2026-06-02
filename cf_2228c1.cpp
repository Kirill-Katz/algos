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
    long long a;
    int n;

    cin >> a; cin >> n;

    array<int, 2> d;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    if (a == 0) {
        cout << d[0] << '\n';
        return;
    }

    long long len = 0;
    long long div = 1;

    while (a / div > 0) {
        div *= 10;
        len++;
    }
    div /= 10;

    long long hsd = a / div;
    if (hsd == d[0] || hsd == d[1]) {
        long long init = 0;
        int j = 0;

        while (j < len) {
            long long c = (a / div) % 10;

            if (c != d[0] && c != d[1]) {
                break;
            }

            init = init * 10 + c;
            div /= 10;
            j++;
        }

        if (j == len) {
            cout << abs(init - a) << '\n';
            return;
        }

        long long lower = init * 10 + d[0];
        long long upper = init * 10 + d[1];

        long long fucking_lower = init * 10 + d[0];
        long long fucking_upper = init * 10 + d[1];

        for (int i = j + 1; i < len; ++i) {
            lower = lower * 10 + d[1];
            upper = upper * 10 + d[0];

            fucking_lower = fucking_lower * 10 + d[0];
            fucking_upper = fucking_upper * 10 + d[1];
        }

        cout << min({ abs(a - lower), abs(a - upper), abs(a - fucking_lower), abs(a - fucking_upper) }) << '\n';
    } else if (hsd > d[0] && hsd >= d[1]) {
        long long upper = d[0] * 10 + d[0];
        long long lower = d[1];

        for (int i = 1; i < len; ++i) {
            upper *= 10;
            upper += d[0];

            lower *= 10;
            lower += d[1];
        }

        cout << min(abs(a - upper), abs(a - lower)) << '\n';
    } else {
        long long upper = d[0];
        long long lower = d[1];

        for (int i = 1; i < len; ++i) {
            if (i != 1) {
                lower *= 10; lower += d[1];
            }

            upper *= 10;
            upper += d[0];
        }

        cout << min(abs(a - upper), abs(a - lower)) << '\n';
    }
}
