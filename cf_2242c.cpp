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

    vector<pair<int,int>> cnt;
    int current = 0;

    for (int i = 0; i < n; ++i) {
        if (i != 0 && a[i-1] != a[i]) {
            cnt.push_back({current, a[i-1]});
            current = 0;
        }

        current++;
    }

    if (current != 0) {
        cnt.push_back({current, a[n - 1]});
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    long long cnt_sum = 0;
    for (auto pr : cnt) {
        pq.push(pr);
        cnt_sum += pr.first;
    }

    int ans = 0;

    while (!pq.empty()) {
        int lower = pq.top().first;
        int unique = pq.size();

        int minimum_sum = cnt_sum - unique * (lower - 1);

        if (k >= minimum_sum && (k - minimum_sum) % unique == 0) {
            ans++;
        }

        while (!pq.empty() && pq.top().first == lower) {
            cnt_sum -= pq.top().first;
            pq.pop();
        }
    }

    cout << ans << '\n';
}
