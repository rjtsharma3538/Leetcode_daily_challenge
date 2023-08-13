// this is leetcode daily challenge of 13 Aug 2023
// problem link : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

class Solution {
public:

    bool help(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(idx>=nums.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        
        bool ans=false;
        for(int i=idx;i<nums.size();i++)
        {
            if(i-idx+1==2&&nums[i]==nums[i-1])
                ans = ans | help(i+1,nums,dp);
            if(i-idx+1==3&&nums[i]==nums[i-1]&&nums[i-1]==nums[i-2])
                ans = ans | help(i+1,nums,dp);
            if(i-idx+1==3&&nums[i]==nums[i-1]+1&&nums[i-1]==nums[i-2]+1)
                ans = ans | help(i+1,nums,dp);
            if(i-idx+1==4)
                break;
        }

        if(ans)
            return dp[idx]=1;
        else 
            return dp[idx]=0;
    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(help(0,nums,dp))
            return true;
        return false;
    }
};
