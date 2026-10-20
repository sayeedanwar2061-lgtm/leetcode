
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> um;
        int left = 0;
        int right = 0;

        int max = 1;

        while(left < n && right < n){
            um[fruits[right]]++;

            while(um.size() > 2){
                um[fruits[left]]--;

                if (um[fruits[left]] == 0) {
                    um.erase(fruits[left]);
                }

                left++;
            }

            int cur = 0;

            for (auto x : um) {
                cur += x.second;
            }

            if(cur > max){
                max = cur;
            }
            right++;
        }
        return max;
    }
};
