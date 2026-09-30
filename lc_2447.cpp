class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = (int)nums.size();

        int ans = 0;
        for (int l = 0; l < n; ++l) {
            int c = 0;
            for (int r = l; r < n; ++r) {
                c = gcd(c, nums[r]);

                if (c == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
