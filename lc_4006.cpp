class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;

        int os = 0;
        int zs = 0;
        for (char c : s) {
            os += c == '0';
            zs += c == '1';

            if (abs(os - zs) <= 1) {
                ans++;
            }
        }

        return ans;
    }
};
