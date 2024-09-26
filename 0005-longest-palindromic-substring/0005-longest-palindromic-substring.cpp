class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.length();
        if (s_len < 2) return s;

        string answer, odd, even; 
        answer = s.substr(0, 1);
        auto from_center = [&](int l, int r)
            {
                while (l >= 0 && r < s_len && s[l] == s[r])
                {
                    --l;
                    ++r;
                }
                return s.substr(l + 1, r - l - 1);
            };

        for (int i = 0; i < s_len - 1; ++i)
        {
            odd = from_center(i, i);
            even = from_center(i, i + 1);

            if (odd.length() > answer.length())
            {
                answer = odd;
            }
            if (even.length() > answer.length())
            {
                answer = even;
            }
        }

        return answer;
    }
};