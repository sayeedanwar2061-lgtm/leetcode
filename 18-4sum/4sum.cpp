class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 3; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            vector<vector<int>> res =
                threeSum(nums, i + 1, target - nums[i]);

            for(auto x : res) {

                ans.push_back({
                    nums[i],
                    x[0],
                    x[1],
                    x[2]
                });
            }
        }

        return ans;
    }


    vector<vector<int>> threeSum(
        vector<int>& nums,
        int start,
        long long target
    ) {

        vector<vector<int>> ans;

        int n = nums.size();

        for(int i = start; i < n - 2; i++) {

            if(i > start && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                long long sum =
                    (long long)nums[i] +
                    nums[j] +
                    nums[k];

                if(sum == target) {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1])
                        j++;

                    while(j < k && nums[k] == nums[k + 1])
                        k--;

                }
                else if(sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};