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

    // first for Alice second for Boberto
    vector<pair<long long,long long>> p(n);

    long long A = 0;
    long long B = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        A += p[i].first;
    }

    for (int i = 0; i < n; ++i) {
        cin >> p[i].second;
        B += p[i].second;
    }

    auto compare = [](const auto& a, const auto& b) -> bool {
        return a.first + a.second > b.first + b.second;
    };

    sort(p.begin(), p.end(), compare);

    for (int i = 0; i < n; ++i) {
        auto [a, b] = p[i];

        if (i % 2 == 0) { // Alice move
            A--;
            B -= b;
        } else { // Bob move
            B--;
            A -= a;
        }
    }

    cout << A - B << '\n';
}
