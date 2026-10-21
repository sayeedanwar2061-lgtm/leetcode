
class Solution {
public:
    string decodeString(string s) {
        string output = "";
        stack<char> lt;

        for (char c : s) {
            if (c == ']') {
                string s1 = "";

                while (!lt.empty() && lt.top() != '[') {
                    s1 = lt.top() + s1;
                    lt.pop();
                }

                if (lt.empty()) continue;
                lt.pop(); // remove '['

                string num1 = "";

                while (!lt.empty() && isdigit(lt.top())) {
                    num1 = lt.top() + num1;
                    lt.pop();
                }

                if (num1.empty()) continue;

                int num = stoi(num1);

                string repeated;
                for (int j = 0; j < num; j++) {
                    repeated += s1;
                }

                for (char x:repeated) {
                    lt.push(x);
                }
            } else {
                lt.push(c);
            }
        }

        while (!lt.empty()) {
            output.push_back(lt.top());
            lt.pop();
        }

        reverse(output.begin(), output.end());
        return output;
    }
};
