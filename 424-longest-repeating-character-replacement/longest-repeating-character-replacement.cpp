class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> um;

        int i = 0;
        int j = 0;

        int max = 0;
        int cur = 0;

        int maxf = 0;

        while(j<s.size()){
            um[s[j]]++;

            if(um[s[j]] > maxf){
                maxf = um[s[j]];
            }

            while((j-i+1) - maxf > k){
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