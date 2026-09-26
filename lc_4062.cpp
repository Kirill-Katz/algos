class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = (int)source.size();

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long diff = target[i] - source[i];

            ans += diff * 1LL;
        }

        return ans == 0;
    }
}
