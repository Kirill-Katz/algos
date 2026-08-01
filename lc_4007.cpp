class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> cnt;
        for (int v : planks) {
            cnt[v]++;
        }

        int n = (int)planks.size();
        vector<pair<long long, int>> vals;
        for (auto [k, v] : cnt) {
            vals.push_back({k, v});
        }

        unordered_map<long long, int> ans;

        int m = (int)vals.size();
        for (int i = 0; i < m; ++i) {
            auto [k1, v1] = vals[i];
                ans[k1] += v1;
            ans[k1 * 2LL] += v1 / 2;

            for (int j = i + 1; j < m; ++j) {
                auto [k2, v2] = vals[j];
                ans[k1 + k2] += min(v2, v1);
            }
        }

        int res = 0;
        for (auto [_, v] : ans) {
            res = max(res, v);
        }

        return res;
    }
};
