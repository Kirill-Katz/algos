#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    vector<int> new_s = s;
    new_s.insert(new_s.begin(), 1 - d);
    new_s.push_back(n + 1);

    auto contrib = [&](int l, int r) {
        return (r - l - 1) / d;
    };

    int cookies = m;
    for (int i = 1; i <= m + 1; ++i) {
        cookies += contrib(new_s[i - 1], new_s[i]);
    }

    int best = INT_MAX;
    int removable = 0;
    for (int i = 1; i <= m; ++i) {
        long long cur = cookies;

        cur -= 1;
        cur -= contrib(new_s[i-1], new_s[i]);
        cur -= contrib(new_s[i], new_s[i+1]);
        cur += contrib(new_s[i-1], new_s[i+1]);

        if (cur < best) {
            best = cur;
            removable = 1;
        } else if (best == cur) {
            removable++;
        }
    }


    cout << best << ' ' << removable << '\n';
}
