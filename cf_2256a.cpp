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
    array<int, 3> nums;
    cin >> nums[0] >> nums[1] >> nums[2];

    ranges::sort(nums);

    if (nums[0] + nums[1] > nums[2]) {
        cout << nums[2] - nums[0] << '\n';
    } else {
        nums[2] = nums[0] + nums[1];
        cout << nums[2] - nums[0] << '\n';
    }
}
