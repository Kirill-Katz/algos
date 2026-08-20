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

    solve();

    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (a[i].size() > a[j].size()) {
            return true;
        } else if (a[i].size() < a[j].size()) {
            return false;
        }

        return a[i] > a[j];
    });

    vector<string> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = a[idx[i]];
    }

    vector<string> excluding_first(k - 1);
    for (int i = 0; i < k - 1; ++i) {
        excluding_first.push_back(sorted_a[i]);
    }

    auto remove_lead_zs = [&](const string& str) {
        string removed;

        bool continue_ = true;
        for (char c : str) {
            if (c != '0') continue_ = false;
            if (continue_) continue;

            removed.push_back(c);
        }

        return removed.empty() ? string("0") : removed;
    };

    auto numeric_max = [&](const string& a, const string& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size() ? a : b;
        }

        return a > b ? a : b;
    };

    sort(excluding_first.begin(), excluding_first.end(), [&](const auto& s1, const auto& s2) {
        if (remove_lead_zs(s1)[0] > remove_lead_zs(s2)[0]) {
            return true;
        }

        return false;
    });

    string max_prefix = remove_lead_zs(sorted_a[k - 1]);
    for (int i = k; i < n; ++i) {
        max_prefix = numeric_max(max_prefix, remove_lead_zs(sorted_a[i]));
    }

    string ans = max_prefix;
    for (const auto& s : excluding_first) {
        ans += s;
    }

    cout << ans << '\n';
}
