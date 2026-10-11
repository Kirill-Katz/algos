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
    string s;
    cin >> s;

    stack<int> st;
    vector<bool> printed(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        int ac = s[i - 1];

        if (ac == '1') {
            st.push(i);
        } else if (ac == '2') {
            if (!st.empty()) {
                printed[st.top()] = true;
                st.pop();
            } else {
                printed[i] = true;
            }
        } else {
            printed[i] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!printed[i]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; ++i) {
        if (!printed[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}
