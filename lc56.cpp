class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        ranges::sort(intervals);

        int n = (int) intervals.size();

        int cl = intervals[0][0];
        int cr = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (l <= cr) {
                cr = max(r, cr);
            } else {
                ans.push_back({ cl, cr });

                cl = l;
                cr = r;
            }
        }

        ans.push_back({ cl, cr });

        return ans;
    }
};
