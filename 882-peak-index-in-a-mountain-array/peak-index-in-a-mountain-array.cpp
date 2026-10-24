class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size() - 2;
        
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }else if(arr[mid] < arr[mid+1]){
                // left side sorted
                low = mid+1;
            }else{
                // right side sorted
                high = mid-1;
            }
        }
        return -1;
    }
};