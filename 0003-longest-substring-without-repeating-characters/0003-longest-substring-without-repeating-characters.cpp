class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string answer = "";
        int result = 0, i;        
        
        for (i = 0; i < s.size(); ++i)
        {
            if (answer.find(s[i]) == -1)
            {
                answer += s[i];
            }
            else
            {
                answer.erase(0, answer.find(s[i]) + 1);
                answer += s[i];
            }
            result = answer.size() > result ? answer.size() : result;
        }
        
        return result;
    }
};