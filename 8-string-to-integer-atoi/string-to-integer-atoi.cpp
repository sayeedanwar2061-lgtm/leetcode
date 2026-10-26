
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        char PorN = '+';
        int singAllowed = 1;

        for (char c : s) {
            if (c == ' ' && singAllowed) {
                continue;
            }
            else if ((c == '+' || c == '-') && singAllowed) {
                PorN = c;
                singAllowed = 0;
            }
            else if (isdigit(c)) {
                singAllowed = 0;
                int digit = c - '0';

                ans = ans * 10 + digit;

                if (PorN == '-' && -ans < INT_MIN)
                    return INT_MIN;

                if (PorN == '+' && ans > INT_MAX)
                    return INT_MAX;
            }
            else {
                break;
            }
        }

        return PorN == '-' ? -ans : ans;
    }
};
