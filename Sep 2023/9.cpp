// this is leetcode daily challenge of 9 Sept 2023
// problem link : https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09

class Solution {
public:

    int help(int target, vector<int>& nums, vector<int> &dp)
    {
        if(target==0)
            return dp[target]=1;
        if(dp[target]!=-1)
            return dp[target];
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
                cnt+=help(target-nums[i],nums,dp);
        }
        return dp[target]=cnt;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return help(target,nums,dp);
    }
};
