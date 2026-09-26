class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        // that dp thing?
        int n = (int)nums.size();

        auto mod = [&](long long v) {
            return (v % k + k) % k;
        };

        vector<int> pref(n + 1);
        pref[0] = 0;

        for (int i = 1; i <= n; ++i) {
            pref[i] = mod(pref[i - 1] + nums[i - 1]);
        }

        vector<int> first(k, -1); // index is v % k value is and index in the array
        vector<int> last(k, -1);

        for (int i = 0; i <= n; ++i) {
            if (first[pref[i]] == -1) {
                first[pref[i]] = i;
            }
        }

        for (int i = n; i >= 0; --i) {
            if (last[pref[i]] == -1) {
                last[pref[i]] = i;
            }
        }

        vector<vector<int>> pos(k, vector<int>{});
        for (int i = 0; i < n; ++i) {
            pos[mod(2LL * nums[i])].push_back(i);
        }

        auto have = [&](int l, int r, int v) -> bool {
            auto it = lower_bound(pos[v].begin(), pos[v].end(), l);
            return it != pos[v].end() && *it < r;
        };

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            if (last[i] == -1) continue;

            ans = max(ans, last[i] - first[i]);

            int r = last[i];
            for (int j = 0; j < k; ++j) {
                if (first[j] == -1) continue;

                int l = first[j];

                int need = mod(pref[r] - pref[l]);

                if (have(l, r, need)) {
                    ans = max(ans, r - l);
                }
            }
        }

        return ans;
    }
};
