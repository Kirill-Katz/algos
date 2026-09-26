class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        // that dp thing?
        int n = (int)nums.size();

        vector<int> pref(n + 1);
        pref[0] = 0;

        for (int i = 1; i <= n; ++i) {
            pref[i] = ((pref[i - 1] + nums[i - 1]) % k + k) % k;
        } // [, )

        int ans = 0;
        for (int l = 0; l < n; ++l) {
            unordered_set<long long> neg;

            for (int r = l + 1; r <= n; ++r) {
                neg.insert((2LL * nums[r - 1] % k + k) % k);
                long long need = (pref[r] - pref[l] % k + k) % k;

                if (neg.contains(need) || need == 0) {
                    ans = max(ans, r - l);
                }
            }
        }

        return ans;
    }
}
