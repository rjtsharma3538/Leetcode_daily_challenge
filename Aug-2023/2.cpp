// this is leetcode daily challenge of 2 Aug 2023
// problem link : https://leetcode.com/problems/permutations/

class Solution {
public:

    void recur(vector<int>& nums, int idx, vector<vector<int>> &ans)
    {
        if(idx==nums.size())
            ans.push_back(nums);
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            recur(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(nums,0,ans);
        return ans;
    }
};
