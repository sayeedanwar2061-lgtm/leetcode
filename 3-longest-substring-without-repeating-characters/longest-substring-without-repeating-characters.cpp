class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;

        int i = 0;
        int j = 0;

        int max = 0;
        int cur = 0;

        while(j<s.size()){
            um[s[j]]++;

            while(um[s[j]] > 1){
                um[s[i]]--;
                i++;
            }

            cur = j-i+1;
            if(cur > max){
                max = cur;
            }
            
            j++;
        }
        
        return max;
    }
};