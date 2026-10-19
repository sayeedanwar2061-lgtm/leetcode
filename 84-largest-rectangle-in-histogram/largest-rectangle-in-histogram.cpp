class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int len = heights.size();

        vector<int> left(len, -1);

        vector<int> right(len, len);

        for(int i=len-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        for(int i=0;i<len;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        int max = 0;

        for(int i=0;i<len;i++){
            int width = right[i] - left[i] - 1;
            int height = heights[i];
            int area = width * height;
            
            if (area > max) {
                max = area;
            }
        }

        return max;
    }
};