class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> um;

        for (char x : s) {
            um[x]++;
        }

        for (char x : t) {
            if (um[x] == 0) {
                return false;
            }
            um[x]--;
        }

        return true;
    }
};