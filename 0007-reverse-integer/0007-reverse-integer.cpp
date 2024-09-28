class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s.size() < 2) return stoi(s);
        string result = "";
        int i = s.size() - 1;
        long long temp;

        if (s[0] == '-') result += "-";

        for (; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                if (s[0] == '-' && i == 1)
                {
                    result += "";
                    break;
                }
                else if (i == 0)
                {
                    result += "";
                    break;
                }
            }

            result += s[i];
        }

        temp = stoll(result);
        if (temp > 2147483647 || temp < -2147483648) return 0;

        return stoi(result);
    }
};