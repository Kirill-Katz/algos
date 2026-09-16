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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> a_orig = a;

    ranges::sort(a);
    vector<pair<long long, int>> cnt;

    for (int i = 0; i < n;) {
        int j = i;

        pair<long long, int> p = {a[i], 0};
        p.first = a[i];

        while(j < n && a[i] == a[j]) {
            p.second++;
            j++;
        }

        cnt.push_back(p);
        i = j;
    }

    map<long long, long long> vals;

    vector<long long> arr_vals;

    if (cnt[0].first != 0) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i < (int)cnt.size(); ++i) {
        long long diff = cnt[i].first - cnt[i - 1].first;

        if (diff % cnt[i - 1].second != 0) {
            cout << -1 << '\n';
            return;
        }

        long long val = diff / cnt[i - 1].second;

        vals[cnt[i - 1].first] = val;
        arr_vals.push_back(val);
    }

    long long last_val = !arr_vals.empty() ? arr_vals.back() + 1 : 1;
    vals[cnt.back().first] = last_val;
    arr_vals.push_back(last_val);

    for (int i = 0; i < (int)arr_vals.size(); ++i) {
        if (arr_vals[i] <= 0) {
            cout << -1 << '\n';
            return;
        }

        if (i >= 1 && arr_vals[i - 1] >= arr_vals[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << vals[a_orig[i]] << ' ';
    }
    cout << '\n';
}
