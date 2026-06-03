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

    int d0;
    int d1;

    cin >> d0;
    cin >> d1;

    long long div = 1;
    int len = 0;
    while (a / div >= 10) {
        div *= 10;
        len++;
    }

    long long lower = 0;
    long long upper = 0;

    vector<long long> pref;

    int i = 0;
    for (; i <= len; ++i) {
        long long c = (a / div) % 10;

        if (c == d0 || c == d1) {
            lower = lower * 10 + (c == d0 ? d0 : d1);
            upper = upper * 10 + (c == d0 ? d0 : d1);
            pref.push_back(c);
        } else {
            break;
        }
        div /= 10;
    }

    if (i == len + 1) {
        cout << 0 << '\n';
        return;
    }

    long long c = (a / div) % 10;

    if (c > d1) {
        for (int j = i; j <= len; ++j) {
            lower = lower * 10 + d1;
        }

        int p = -1;
        for (int j = (int)pref.size() - 1; j >= 0; --j) {
            if (pref[j] < d1) {
                p = j;
                break;
            }
        }

        if (p == -1) {
            upper = d0 == 0 ? d1 : d0;
            for (int j = 1; j <= len + 1; ++j) {
                upper = upper * 10 + d0;
            }
        } else {
            upper = 0;
            pref[p] = d1;
            for (int j = 0; j <= p; ++j) {
                upper = upper * 10 + pref[j];
            }
            for (int j = p + 1; j <= len; ++j) {
                upper = upper * 10 + d0;
            }
        }
    } else if (c < d0) {
        for (int j = i; j <= len; ++j) {
            upper = upper * 10 + d0;
        }

        int p = -1;

        for (int j = (int)pref.size() - 1; j >= 0; --j) {
            if (pref[j] > d0) {
                p = j;
                break;
            }
        }

        if (p == -1) {
            lower = d1;
            for (int j = 1; j <= len - 1; ++j) {
                lower = lower * 10 + d1;
            }
        } else {
            lower = 0;
            pref[p] = d0;

            for (int j = 0; j <= p; ++j) {
                lower = lower * 10 + pref[j];
            }

            for (int j = p + 1; j <= len; ++j) {
                lower = lower * 10 + d1;
            }
        }
    } else {
        lower = lower * 10 + d0;
        upper = upper * 10 + d1;

        for (int j = i + 1; j <= len; ++j) {
            lower = lower * 10 + d1;
            upper = upper * 10 + d0;
        }
    }

    cout << min(abs(a - upper), abs(a - lower)) << '\n';
}
