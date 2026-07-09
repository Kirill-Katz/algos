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

    // the number of pairs such that s[i] == s[j] is invariant
    // a pair is plesant iff:
    // i + 1 > j, i.e we need at least one element between i and j
    // a substring contains the maximum number of plesant pairs
    // unless there exists a substring of the form ab..b or bb...bb

    vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
        cnt[s[i]-'a']++;
    }

    priority_queue<pair<int,char>> pq;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c - 'a'] > 0) {
            pq.push({ cnt[c-'a'], c });
        }
    }

    string ans;
    while (!pq.empty()) {
        vector<pair<int,char>> used;

        for (int i = 0; i < 3 && !pq.empty(); ++i) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            ans.push_back(ch);
            cnt--;

            if (cnt > 0) {
                used.push_back({ cnt, ch });
            }
        }

        for (auto p : used) {
            pq.push(p);
        }
    }

    cout << ans << '\n';
}
