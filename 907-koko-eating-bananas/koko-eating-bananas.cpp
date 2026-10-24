class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int low = 1;
        int high = 0;

        for (int pile:piles){
            high = max(high,pile);
        }

        int ans = -1;

        while (low <= high){
            int k = low + (high - low)/2;

            if(canEat(piles,h,k)){
                ans = k;
                high = k-1;
            }else{
                low = k+1;
            }
        }
        return ans;
    }

    public:
    int canEat(vector<int> piles, int h,int k) {
        long long hours = 0;
        for(int pile:piles){
            hours += (pile + k - 1)/k;
        }
        return hours <= h;
    }
};