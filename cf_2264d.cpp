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

    // [_____] 1 [_____] 1 [_____] 1 [______]
    //    x         y         z         w

    int base = (n - 3) / 4;

    long long zero_bad = [&](long long x, long long y, long long z, long long w) {
        return 1LL * x * (x + 1) / 2 +
        1LL * y * (y + 1) / 2 +
        1LL * z * (z + 1) / 2 +
        1LL * w * (w + 1) / 2;
    };

    string construct_ans = [&](long long x, long long y, long long z, long long w) {
        string ans(n, "0");
        ans[x] = '1';
        ans[y + x + 1] = '1';
        ans[y + x + z + 2] = '1';
        ans[y + x + z + w + 3] = '1';

        return ans;
    };

    vector<pair<long long, string>> ans;

    // even, even
    {
        long long y = base;
        long long z = base;

        if (y & 1) {
            y++;
        }

        if (z & 1) {
            z++;
        }

        long long x = ((n - 3) - y - z) / 2;
        long long w = (n - 3) - x - y - z;

        long long even_even_add = (x + 1) * (z + 1) + (y + 1) * (w + 1);
        ans.push_back({ even_even_add + zero_bad(x, y, z, w), construct_ans(x, y, z, w) };
    }

    // odd, even
    {
        long long y = base;
        long long z = base;

        if (!(y & 1)) {
            y++;
        }

        if (z & 1) {
            z++;
        }

        long long x = ((n - 3) - y - z) / 2;
        long long w = (n - 3) - x - y - z;

        long long odd_even_add = (y + 1) * (w + 1);
        ans.push_back({ odd_even_add + zero_bad(x, y, z, w), construct_ans(x, y, z, w) };
    }

    // even, odd
    {
        long long y = base;
        long long z = base;

        if (y & 1) {
            y++;
        }

        if (!(z & 1)) {
            z++;
        }

        long long x = ((n - 3) - y - z) / 2;
        long long w = (n - 3) - x - y - z;

        long long even_odd_add = (x + 1) * (z + 1);
        ans.push_back({ even_odd_add + zero_bad(x, y, z, w), construct_ans(x, y, z, w) };
    }


}

