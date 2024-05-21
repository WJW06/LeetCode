class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}, {nums[0]}};
        
        for (int i = 1; i < nums.size(); ++i)
        {
            vector<vector<int>> arr = result;
            for(auto curArr : arr)
            {
                curArr.push_back(nums[i]);
                result.push_back(curArr);
            }
        } 
        
        return result;
    }
};