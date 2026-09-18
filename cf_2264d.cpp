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

    // let's view all the segments of size 1, 2, 3, ...
    //
    // for segments of size 1 we have a hard limit of n - 3 wrong segments, because we have only 3 1s in the binary
    // string
    //
    // Assume we can only have 1 ones. Then:
    // we want to divide the string into two equal parts with 1 at the middle, because
    // that reduces the number of 0 containing segments.
    //
    // Assume we can only have 2 ones. Then:
    // we want to divide the string into three equal parts with the middle part having an odd number
    // of zeros. This is because an even number of zeros between them causes the middle segment to become divisible by 3.
    //
    // Assume we can only have 3 ones. Then - it is hard
    // - we probably want the "base string" to not be divisible by 3.
    // - if the base string is not divisible by 3 then we are forced to get 2 substrings divisible by
    // - we want to have 4 segments containing zeros
    // -
    //
    // maybe 2 ones is as good as it gets?
    //
    // the problem is that with 2 ones we have only 3 segments were we have n^2 explosion of bad segments,
    // while with 3 ones, each segment is smaller, but now the overall structure is not nice, and we are forced
    // to have n^2 explosions containings 1.

    if (n == 1) {
        cout << "1" << '\n';
        return;
    }

    if (n == 2) {
        cout << "11" << '\n';
        return;
    }

    int total = n - 2;

    int mid = total / 3;

    if (!(mid & 1)) {
        mid++;
    }

    int left = (total - mid) / 2;
    int right = total - left - mid;

    string s = "";

    for (int i = 0; i < left; ++i) {
        s.push_back('0');
    }

    s.push_back('1');

    for (int i = 0; i < mid; ++i) {
        s.push_back('0');
    }

    s.push_back('1');

    for (int i = 0; i < right; ++i) {
        s.push_back('0');
    }

    cout << s << '\n';
}

