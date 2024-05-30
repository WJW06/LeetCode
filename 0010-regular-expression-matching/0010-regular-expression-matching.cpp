class Solution {
    vector<vector<int>> dp;
    
    bool isEqual(char s, char p) {
        if (p == '.') // When the comparison character is .
            return true;
        return s == p; // character comparison
    }
    
    bool isMatch(string& s, string& p, int sInd, int pInd) {
        if (sInd >= s.size()) { // If the s position is greater than the last index
            bool ans = true; // answer variable
            for (int i = pInd; i < p.size(); i++) { // Repeat for the remaining length of p
                if (i + 1 < p.size() && p[i + 1] == '*') { // If the part following p does not exceed the last index of p and is *
                    i++; // Skip to next character
                    continue;
                }
                ans = false; // If the above conditions are not met, the value false is entered in ans(it must be false as there are remaining characters after comparison).
                break; // stop repeating
            }
            return ans;
        }
        
        if (pInd >= p.size()) { // If the p position is greater than the last index
            return false; // (= if there are characters in s that could not be compared)
        }

        int& ret = dp[sInd][pInd]; // Get the current comparison position
        if (ret != -1) return ret; // Returns if it has already been compared
        ret = false;

        if (pInd + 1 < p.size() && p[pInd + 1] == '*') { // If the part following p does not exceed the last index of p and is *
            ret = isMatch(s, p, sInd, pInd + 2); // *After comparing with the letters behind it, whether or not the answer is correct is put into ret.
            for (int i = sInd; i <= s.size(); i++) { // Repeat for the remaining i length
                if (!isEqual(s[i], p[pInd])) break; // Stop when an unmatched character is encountered
                ret |= isMatch(s, p, i + 1, pInd + 2); // s moves one space (next character) p moves two spaces (letter after *) and starts comparison
            }
        }
        else if (p[pInd] == '.') { // If p position is .
            ret = isMatch(s, p, sInd + 1, pInd + 1); // Both s and p move to the next character
        }
        else { // If the p position is a character without *
            if (s[sInd] != p[pInd]) ret = false;  // false if characters are not equal
            else ret = isMatch(s, p, sInd + 1, pInd + 1); // If the characters are the same, compare the next character
        }

        return ret;
    }
    
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size(), vector<int>(p.size(), -1)); // Assign dp as the length of s * length of p and fill the value with -1.
        bool answer = isMatch(s, p, 0, 0);
        return answer;
    }
};