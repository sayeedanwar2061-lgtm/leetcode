
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;

        ans.push_back({1});
        numRows--;

        while (numRows--) {
            int tsize = ans.back().size();
            vector<int> temp(tsize + 1, 1);

            int low = 1;
            int high = tsize - 1;

            while (low < high) {
                temp[low] = ans.back()[low] + ans.back()[low - 1];
                temp[high] = ans.back()[high - 1] + ans.back()[high];
                low++;
                high--;
            }

            if (low == high) {
                temp[low] = ans.back()[low - 1] + ans.back()[low];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
