class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string output = "";

        for(char ch : s){
            if(ch == ' '){
                while(!st.empty()){
                    output.push_back(st.top());
                    st.pop();
                }
                output.push_back(' ');
            }else{
                st.push(ch);
            }
        }

        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }

        return output;
    }
};