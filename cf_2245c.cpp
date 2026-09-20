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
    // mex can be increasing only
    //
    // if floor(log_2(n - 1)) < floor(log_2(k)) then we can't possibly solve this because just don't have the bits
    //
    // assume: we can obtain arbirary values for mex using this construction
    //
    // we necesarily have to have an n in the mex construction
    // we need to pick a value a, such that a ^ n = k and all the other values cancel out.
    //
    // what if we try to keep the prefix mex to be 0 before a, and then equal to a the next segment until we get to the last value
    //
    // in other words we get the construction:
    //
    // 00000aaaaan
    //
    // where there are an odd number of a's and any number of 0s (so this works for both even and odd n, as we can add or remove a 0 from the left)
    //

    int n;
    cin >> n;
    int k;
    cin >> k;

    if (n == 1 && k != 1) {
        cout << "NO" << '\n';
        return;
    }

    if (k == 0) {
        for (int i = 0; i < 31; ++i) {
            if ((1 << i) == (n + 1)) {
                cout << "YES" << '\n';

                for (int i = 0; i < n; ++i) {
                    cout << i << ' ';
                }
                cout << '\n';
                return;
            }
        }

        cout << "NO" << '\n';
        return;
    }

    int b = n ^ k; // find the target b
    if (b > n) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    vector<int> ans(n);

    int first_start = b - 1; // start value of the first block
    int second_start = n - 1; // start value of the second one

    int j = 0;

    if (n & 1 && (b & 1)) { // if n is odd and there are an even number of vals to the left
        ans[0] = n - 1; // we want to put on more number to make the number of zeros to the left odd
        second_start--; // thus making the number of values to the right even, which will cancel them
        ++j;
    }

    while (first_start >= 0) {
        ans[j] = first_start--;
        j++;
    }

    while (second_start >= b) {
        ans[j] = second_start--;
        j++;
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
