class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> arr;

        while (x > 0)
        {
            arr.push_back(x % 10);
            x /= 10;
        }

        int l = 0;
        int r = arr.size() - 1;

        while (true)
        {
            if (l > arr.size() || r < 0) break;
            if (arr[l] != arr[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};