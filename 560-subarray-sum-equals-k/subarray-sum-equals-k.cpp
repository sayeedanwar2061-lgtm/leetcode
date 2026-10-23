class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> v;
        int sum = 0;

        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
            v.push_back(sum);
        }

        int count = 0;

        for(int i = 0;i<nums.size();i++){
            int need = v[i] - k;

            if (v[i] == k) {
                count++;
            }

            for(int j = 0;j<i;j++){
                if(v[j] == need){
                    count++;
                }
            }
        }

        return count;
    }
};