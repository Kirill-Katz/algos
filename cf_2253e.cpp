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
    for (int  i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // So from the perspective of an a[i] we have a range from [max(0, i - a[i]), min(n - 1, i + a[i])] inside which j cannot be for it
    // to be compatible with i.
    //
    // So when we see a[i] we would like to know the maximum possible score that is achievable at position i - a[i] - 1 where the last element in that
    // sequence has a maximum <= a[i], we don't really care about the maximum of that specific last element we just need it to be <= a[i] at position i - a[i] - 1.
    //
    // So we need some kind of a set of { best_value, max_right } and we could decrease max_right every time we go to the right.
    //
    // Decreasing seems unnecessary. At some position i, we want to know the best possible score achievable at position dp[a[i] - i - 1]. What
    // we also need is that the set that produces that maximum value should have for all j, a[j] < i - j <=>  a[j] + j < i, but we don't even need to
    // consider all j, we can only use max(a[j] + j) in that set as a key, and then as a value we would have the score inside that set.
    // This way, we would do:
    // long long best = [some_datastructure].find(i); // finds the best score with key < i
    // [some_datastructure].insert({ a[i] + i, best })
    //

    cout << "idk" << '\n';
}
