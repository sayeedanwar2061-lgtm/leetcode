
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                int ans = 0;

                if (token == "+") {
                    ans = num1 + num2;
                }
                else if (token == "-") {
                    ans = num1 - num2;
                }
                else if (token == "*") {
                    ans = num1 * num2;
                }
                else if (token == "/") {
                    ans = num1 / num2;
                }

                st.push(ans);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
