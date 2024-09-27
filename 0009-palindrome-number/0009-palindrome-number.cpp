class Solution {
public:
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        int l = 0;
        int r = s.size()-1;
        while(l<=r)
        {
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};