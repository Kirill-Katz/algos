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

    ranges::sort(a);
    vector<pair<int,int>> hist;

    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && a[i] == a[j]) {
            j++;
        }

        hist.push_back({ a[i], j - i });
        i = j;
    }

    vector<long long> prefix(hist.size() + 1);
    prefix[0] = 0;

    for (int i = 1; i <= (int)hist.size(); ++i) {
        prefix[i] = prefix[i - 1] + hist[i - 1].second * 1LL;
    }

    long long ans = 0;
    int l = 0, r = 0;

    while (l < (int)hist.size()) {
        while (r + 1 < (int)hist.size() && hist[r].first + 1 == hist[r + 1].first && r - l + 1 < k) {
            r++;
        }

        ans = max(ans, prefix[r + 1] - prefix[l]);

        if (r - l + 1 == k) {
            l++;
            continue;
        }

        l = r + 1;
        r = l;
    }

    cout << ans << '\n';
}
