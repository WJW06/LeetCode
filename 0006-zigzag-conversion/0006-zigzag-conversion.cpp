class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;
        vector<string> v(numRows);
        string result = "";
        int i = 0, j = 0;
        bool d = true;

        while (i < s.length())
        {
            if (j == 0) d = true;
            else if (j == numRows - 1) d = false;
            v[j] += s[i++];
            j = d ? j += 1 : j -= 1;
        }

        for (i = 0; i < v.size(); ++i)
        {
            result += v[i];
        }

        return result;
    }
};