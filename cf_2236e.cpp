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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // might be binary search, because the function of the answer is monotonic, like TTFF style
    // the ans is also bounded: 0 <= ans <= n / 2

    auto check = [&](int v) {
        vector<int> cnt(n + 1);
        unordered_set<long long> st;

        auto key = [](int start, int finish) {
            return (1LL * (uint32_t) start << 32) | (uint32_t)finish;
        };

        auto undo_key = [](long long z) {
            int x = (int)(z >> 32);
            int y = (int)(z & 0xffffffff);
            return pair<int,int>{x, y};
        };

        for (int i = 0; i < v; ++i) {
            cnt[a[i]]++;
        }

        for (int i = 0; i <= n - v; ++i) {
            if (i > 0) {
                cnt[a[i - 1]]--;
                cnt[a[v + i - 1]]++;
            }

            for (int c = 0; c <= n; ++c) {
                int local = 0;

                if (cnt[c] == 0) {
                    continue;
                }

                if (cnt[c] > 1) {
                    break;
                }

                int j = c;
                while (j <= n && cnt[j] == 1) {
                    j++;
                }

                if (j - c == v) {
                    st.insert(key( c, c + v - 1));
                }
            }
        }

        for (long long k : st) {
            auto [x, y] = undo_key(k);

            long long lower = key(x - v, x - 1);
            long long upper = key(y + 1, y + v);

            if (st.contains(lower) || st.contains(upper)) {
                return true;
            }
        }

        return false;
    };


    int l = 0, r = n / 2;

    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}
