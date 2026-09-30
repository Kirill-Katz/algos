class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        ranges::sort(changed, greater<int>());

        int n = (int)changed.size();

        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            ms.insert(changed[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int v = changed[i];

            if (!ms.contains(v) || v % 2) {
                continue;
            }

            if (!ms.contains(v / 2)) {
                return {};
            } else {
                auto it_1 = ms.find(v);
                ms.erase(it_1);

                auto it_2 = ms.find(v / 2);
                if (it_2 == ms.end()) {
                    return {};
                }

                ms.erase(it_2);
                ans.push_back(v / 2);
            }
        }

        if (!ms.empty()) {
            return {};
        }

        return ans;
    }
};
