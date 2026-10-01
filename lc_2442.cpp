class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<string> st;

        for (int v : nums) {
            string s;
            int div = 1;

            while (v / div > 0) {
                int vi = (v / div) % 10;

                s.push_back(vi + '0');
                div *= 10;
            }

            string rev_s;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '0' && (int)rev_s.size() == 0) continue;
                rev_s.push_back(s[i]);
            }

            string non_rev_s;
            reverse(s.begin(), s.end());
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '0' && (int)non_rev_s.size() == 0) continue;
                non_rev_s.push_back(s[i]);
            }

            st.insert(non_rev_s);
            st.insert(rev_s);
        }

        return (int) st.size();
    }
};
