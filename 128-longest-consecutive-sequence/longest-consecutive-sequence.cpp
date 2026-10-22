
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.count(num - 1)) continue;

            int curr = num;
            while (st.count(curr + 1)) {
                curr++;
            }

            longest = max(longest, curr - num + 1);
        }

        return longest;
    }
};
