class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int length = 0;
        int max = 0;

        for(auto num : nums){
            s.insert(num);
        }

        for(auto x : s){
            if(s.count(x-1)){
                length++;
            }else{
                length = 1;
            }
            if(length > max){
                max = length;
            }
        }
        return max;
    }
};