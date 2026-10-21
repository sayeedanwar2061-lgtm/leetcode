class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char x : s){
            if(x == ')' && !st.empty() && st.top() == '('){
                st.pop();
            }else if(x == '}' && !st.empty() && st.top() == '{'){
                st.pop();
            }else if(x == ']' && !st.empty() && st.top() == '['){
                st.pop();
            }else{
                st.push(x);
            }
        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};