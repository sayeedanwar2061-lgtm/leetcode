class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string ans = "";

        if (strs.empty()) return ans;

        while (true) {
            char c = '\0';

            for (string s : strs) {
                if (i >= s.size()) {
                    return ans;
                }

                if (c == '\0') {
                    c = s[i];
                } else if (c != s[i]) {
                    return ans;
                }
            }

            ans += c;
            i++;
        }

        return ans;
    }
};