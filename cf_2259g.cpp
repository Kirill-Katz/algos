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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // think in terms of gaps.
    // then removing an element is mergin two gaps.
    // if the gap > k we need to distribute gap - k elements to the right
    //
    // each gap to the right has a capacity defined by k - gap_(i + j) and a cost of j.
    //
    // so we can think in terms of segments, for example if we have k = 5 and
    // a 3 b 4 c 2 d 3 e 2 f
    // where the letters are the numbers and the numbers the gap sizes
    // and we remove c we get:
    // a 3 b 6 d 3 e 2 f
    // so our segments are:
    // overflow in [1, 2] => cost 1
    // overflow in [3, 5] => cost 2
    // overflow in [6, inf] => cost 3
    //
    // so now if we locate the segment our overflow is inside we can just sum up the (r - l) * cost for every
    // previous segment and then do (overflow - sum (r - l)) * cost of segment we are inside

    vector<int> gaps(n - 1);
    for (int i = 1; i < n; ++i) {
        gaps[i - 1] = a[i] - a[i - 1];
    }

    int m = n - 1;
    vector<int> cap(m);
    for (int i = 0; i < m; ++i) {
        cap[i] = k - gaps[i];
    }

    vector<long long> prefix(m);
    prefix[0] = cap[0];

    for (int i = 1; i < m; ++i) {
        prefix[i] = cap[i] + prefix[i - 1];
    }

    vector<long long> pref_score(m);
    pref_score[0] = cap[0] * 1LL;
    for (int i = 1; i < m; ++i) {
        pref_score[i] = pref_score[i - 1] + 1LL * (i + 1) * cap[i];
    }

    auto get_score = [&](int i) { // we merge two gaps [a, b], i is the index of b
        long long sub = prefix[i]; // prefix sum to the left of the segment we are interested
        long long overflow = gaps[i - 1] + gaps[i] - k;

        if (overflow <= 0) {
            return 0LL;
        }

        int l = min(i + 1, m - 1);
        int r = m - 1;

        // FFTT
        while (l < r) {
            int mid = l + (r - l) / 2;

            long long actual = prefix[mid] - sub;

            if (actual < overflow) { // F case
                l = mid + 1;
            } else { // T case
                r = mid;
            }
        }

        if (prefix[l] - sub >= overflow) { // we are good
            long long weighted_before = (pref_score[l - 1] - pref_score[i]);
            long long non_weighted = prefix[l - 1] - prefix[i];

            long long weighted_norm_before = weighted_before - 1LL * (i + 1) * non_weighted;

            long long pos_inside = overflow - non_weighted;
            long long weighted_inside = pos_inside * (l - i);

            return weighted_norm_before + weighted_inside;
        } else { // we used all caps
            long long weighted_before = (pref_score[l] - pref_score[i]);
            long long non_weighted = prefix[l] - prefix[i];

            long long weighted_norm_before = weighted_before - 1LL * (i + 1) * non_weighted;

            long long pos_inside = overflow - non_weighted;
            long long weighted_inside = pos_inside * (l - i + 1);

            return weighted_norm_before + weighted_inside;
        }
    };

    vector<long long> ans(n);
    ans[0] = 0LL;
    ans[n - 1] = 0LL;

    for (int i = 1; i < m; ++i) {
        ans[i] = get_score(i);
    }

    for (long long v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
