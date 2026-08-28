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

    vector<int> vals(n);
    vector<int> type(n);

    for (int i = 0; i < n; ++i) {
        char c, v;
        cin >> c >> v;

        type[i] = c;
        vals[i] = v;
    }

    // Let's figure out what to do if we only have value of the type 's'.
    // if vals[i - 1] == vals[i] then for all j < i, p[j] < p[i].
    // vals[i] - vals[i - 1] tells us the number of numbers, p[j], s.t j < i and p[j] < p[i].
    //
    // if we had the suffix we would be able to determine the number.
    //
    //


}
