#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> g(n);

        for (int i = 0; i < edges.size(); ++i) {
             int p = edges[i][0];
             int v = edges[i][1];

             g[p].push_back(v);
             g[v].push_back(p);
        }

        auto dfs = [&](auto&& self, int v, int p) -> long long {
            long long finish_time = baseTime[v];
            long long earliest = LLONG_MAX;
            long long latest = -1;

            bool is_leaf = true;
            for (int u : g[v]) {
                if (u == p) continue;
                is_leaf = false;

                long long f_time = self(self, u, v);
                earliest = min(f_time, earliest);
                latest = max(f_time, latest);
            }

            if (is_leaf) {
                return finish_time;
            }

            long long own_dur = (latest - earliest) + baseTime[v];
            finish_time = own_dur + latest;

            return finish_time;
        };

        return dfs(dfs, 0, -1);
    }
};

