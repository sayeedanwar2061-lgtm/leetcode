class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;

        string output = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch == ' ' && st.empty()) {
                continue;
            }
            else if (ch == ' ' && !st.empty()) {
                while (!st.empty()) {
                    output.push_back(st.top());
                    st.pop();
                }
                output.push_back(' ');
            }
            else {
                st.push(ch);
            }
        }

        while (!st.empty()) {
            output.push_back(st.top());
            st.pop();
        }

        if (!output.empty() && output.back() == ' ') {
            output.pop_back();
        }

        return output;
    }
};