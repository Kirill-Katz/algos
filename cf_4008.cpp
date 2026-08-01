class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        // b-search?
        int n = monsters.size();

        vector<long long> temp(n + 1);
        for (int i = 0; i < boosts.size(); i++) {
            int l = boosts[i][0];
            int r = boosts[i][1];
            int v = boosts[i][2];

            temp[l] += v;
            temp[r + 1] -= v;
        }

        vector<long long> bon(n);
        bon[0] = temp[0];
        for (int i = 1; i < n; ++i) {
            bon[i] = bon[i - 1] + temp[i];
        }

        auto check = [&](long long s) -> bool {
            for (int i = 0; i < n; ++i) {
                if (s + bon[i] >= monsters[i]) {
                    s = max(0LL, s - monsters[i]);
                } else {
                    return false;
                }
            }
            return true;
        };

        // FFTT
        long long l = 0;
        long long r = 1e18 + 1;

        while (l < r) {
            long long m = l + (r - l) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
