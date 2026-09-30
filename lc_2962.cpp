class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int> places;

        int max_v = *max_element(nums.begin(), nums.end());
        int n = (int) nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] == max_v) {
                places.push_back(i);
            }
        }

        if (places.size() < k) {
            return 0;
        }

        // k = 2
        // 0 1 2
        // 2 2 3
        // 0 1 2
        int m = (int)places.size();
        long long ans = 0;
        places.push_back(-1);

        for (int i = 0; i + k - 1 < m; ++i) {
            long long prev = i == 0 ? -1 : places[i - 1];
            long long block = places[i] - prev;
            long long r = places[i + k - 1];

            ans += block * (n - r);
        }

        return ans;
    }
};
