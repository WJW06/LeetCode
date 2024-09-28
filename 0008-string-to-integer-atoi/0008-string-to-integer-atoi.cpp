class Solution {
public:
    int myAtoi(string s) {
        int i = 0, m = 1, result = 0;

        if (s.length() == 0) {
            return 0;
        }

        while (isspace(s[i])) {
            ++i;
        }

        m = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }

        while (isdigit(s[i])) {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7)) {
                return m == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }
        return m * result;
    }
};