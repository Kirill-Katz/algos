class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       // two contiguous subarrays from the left and the
       // right s.t the sum is x
        int n = (int)nums.size();

        vector<long long> p(n);
        vector<long long> s(n);
        p[0] = nums[0];
        s[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] + nums[i];
        }

        for (int i = n - 2; i >= 0; --i) {
            s[i] = s[i + 1] + nums[i];
        }

        unordered_map<long long, int> suf;
        unordered_map<long long, int> pref;

        for (int i = 0; i < n; ++i) {
            suf[s[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            pref[p[i]] = i;
        }

        int ans = INT_MAX;
        for (int l = 0; l < n; ++l) {
            long long v = p[l];

            if (x - v == 0) {
                ans = min(ans, l + 1);
                continue;
            }

            if (suf.contains(x - v)) {
                auto it = suf.find(x - v);
                auto [v, r] = *it;

                if (r > l) {
                    ans = min(ans, (l + 1) + (n - r));
                }
            }
        }

        for (int r = 0; r < n; ++r) {
            long long v = s[r];
            if (x - v == 0) {
                ans = min(ans, n - r);
                continue;
            }

            if (pref.contains(x - v)) {
                auto it = pref.find(x - v);
                auto [v, l] = *it;

                if (r > l) {
                    ans = min(ans, (l + 1) + (n - r));
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
