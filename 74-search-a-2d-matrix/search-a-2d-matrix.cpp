class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int n = (r*c);

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int x = mid / c;
            int y = mid % c;
            
            if(matrix[x][y] == target){
                return true;
            }else if(matrix[x][y] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};