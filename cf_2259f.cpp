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

    vector<int> a(n);
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> s;

    // this is a block thing game.
    //
    // assume we have a 111001000 string that we perform only in order operations
    //
    // then we have the following configuration:
    // 3 -> -2
    // 1 -> -3
    // every operation decreases the number of inversions by the sum of values and decreases the top key by 1, like this:
    // 3 -> -2
    // 1 -> -3
    // -------
    // 2 -> -2
    // 1 -> -3
    // -------
    // 1 -> -2
    // 1 -> -3
    // ...
    //
    // Assume the full model with 2 operations. From 0s POV we have:
    // 3 -> -1
    // 2 -> -3
    // same thing: an operation decreases the top most key by 1.
    // so:
    // 2 -> -1
    // 2 -> -3
    // ------
    // 1 -> -1
    // 2 -> -3
    // ------
    // 0 -> -1
    // 2 -> -3
    // ....
    // BUT look what happens to the 1s table. Every 0 operation increases bottom most value by 1. For example:
    //
    // Assume before operations:
    // 1s:
    // 3 -> -2
    // 1 -> -3
    // 0s:
    // 3 -> -1
    // 2 -> -3
    //
    // Apply for 1 we get:
    // From: 111001000
    // To:   110010001
    // inversions = inversions - 5
    //
    // 1s:
    // 2 -> -2 # decrease key by 1
    // 1 -> -3
    //
    // 0s:
    // 3 -> -1
    // 2 -> -2 # increase val by 1
    // Each operation decreases the number of inversions by the sum of values for non zero keys, so we need to keep track of these values.

    long long init = 0;
    int o = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            o++;
        } else {
            init += o;
        }
    }

    deque<pair<int,int>> ones_;
    deque<pair<int,int>> zeros_;

    long long one_op = 0;
    long long zero_op = 0;

    for (int i = 0; i < n;) {
        if (a[i] == 0) {
            ++i;
            continue;
        }

        int os = 0;
        int zs = 0;

        int j = i;

        while (j < n && a[j] == 1) {
            os++;
            j++;
        }

        while (j < n && a[j] == 0) {
            zs++;
            j++;
        }

        one_op += zs;

        if (zs > 0) {
            ones_.push_back({ os, zs });
        }

        i = j;
    }

    for (int i = n - 1; i >= 0;) {
        if (a[i] == 1) {
            --i;
            continue;
        }

        int os = 0;
        int zs = 0;

        int j = i;

        while (j >= 0 && a[j] == 0) {
            zs++;
            j--;
        }

        while (j >= 0 && a[j] == 1) {
            os++;
            j--;
        }

        zero_op += os;

        if (os > 0) {
            zeros_.push_back({ zs, os });
        }

        i = j;
    }

    auto apply = [](auto& main, auto& sec, auto& main_op, auto& sec_op) {
        if (!main.empty()) {
            auto& [k, v] = main.front();
            k--;

            if (k == 0) {
                main_op -= v;
                main.pop_front();
            }
        }

        if (!sec.empty()) {
            auto& [k, v] = sec.back();
            v--;
            sec_op -= 1;

            if (v == 0) {
                sec.pop_back();
            }
        }
    };

    cout << init << ' ';
    for (char c : s) {
        if (c == '1') {
            init -= one_op;
            cout << init << ' ';

            apply(ones_, zeros_, one_op, zero_op);
        } else {
            init -= zero_op;
            cout << init << ' ';

            apply(zeros_, ones_, zero_op, one_op);
        }
    }

    cout << '\n';
}
