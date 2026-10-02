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

    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (i % 2) {
            odd.push_back(v);
        } else {
            even.push_back(v);
        }
    }

    if (n == 1 || n == 2) {
        cout << "YES" << '\n';
        return;
    }

    vector<pair<int,int>> ans;
    ans.reserve(odd.size() + even.size());

    std::size_t oi = 0;
    std::size_t ei = 0;

    ranges::sort(odd, greater<int>());
    ranges::sort(even, greater<int>());

    auto take = [&](const std::vector<int>& v, std::size_t& ptr, int cnt) -> bool {
        if (ptr >= v.size()) {
            return true;
        }

        int first = v[ptr++];
        int second = -1;

        if (cnt == 2 && ptr < v.size()) {
            second = v[ptr++];
        }

        const auto& prev = ans.back();

        if (first != -1 && prev.first < first) {
            return false;
        }

        if (second != -1 && prev.second < second) {
            return false;
        }

        ans.push_back({first, second});
        return true;
    };

    bool use_even;

    if (odd.empty()) {
        use_even = true;
    } else if (even.empty()) {
        use_even = false;
    } else {
        use_even = even[0] > odd[0];
    }

    if (use_even) {
        int mx = even[ei++];
        ans.push_back({mx,mx});

        while (oi < odd.size() || ei < even.size()) {
            if (!take(odd, oi, 2) || !take(even, ei, 2)) {
                cout << "NO" << '\n';
                return;
            }
        }
    } else {
        int mx = odd[oi++];
        ans.push_back({mx,mx});

        while (oi < odd.size() || ei < even.size()) {
            if (!take(even, ei, 2) || !take(odd, oi, 2)) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}
