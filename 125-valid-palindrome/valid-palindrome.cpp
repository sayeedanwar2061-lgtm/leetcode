class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for (char i : s) {
            if (isalnum(i)) {
                newS += tolower(i);
            }
        }

        int left = 0;
        int right = newS.size()-1;

        while(left<right){
            if(newS[left] != newS[right]){
                return false;
            }
            left++;right--;
        }
        return true;
    }
};