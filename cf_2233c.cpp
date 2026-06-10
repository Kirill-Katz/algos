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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    int total_open = 0;
    int total_close = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            total_open++;
        } else {
            total_close++;
        }
    }

    int ans_val = INT_MAX;
    string ans_const;

    for (int x = 0; x <= k; ++x) {
        int skip_open = k - x;
        int skip_close = x;

        int seen_open = 0;
        int seen_close = 0;

        int open = 0;
        int pairs = 0;

        string local(n, '0');

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (seen_open < skip_open) {
                    local[i] = '1';
                    seen_open++;
                    continue;
                }

                seen_open++;
                open++;
            } else {
                if (total_close - seen_close <= skip_close) {
                    local[i] = '1';
                    seen_close++;
                    continue;
                }

                if (open > 0) {
                    open--;
                    pairs += 2;
                }

                seen_close++;
            }
        }

        if (pairs < ans_val) {
            ans_const = std::move(local);
            ans_val = pairs;
        }
    }

    cout << ans_const << '\n';
}
