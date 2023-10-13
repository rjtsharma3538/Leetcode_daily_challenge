// this is leetcode daily challenge of 13 Oct 2023
// problem link : https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=daily-question&envId=2023-10-13

class Solution {
public:

    int help(int idx, vector<int> &cost, vector<int> &dp)
    {
        if(idx==0||idx==1)
            return dp[idx]=0;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1=INT_MAX,op2=INT_MAX;
        if(idx-1>=0)
            op1=help(idx-1,cost,dp)+cost[idx-1];
        if(idx-2>=0)
            op2=help(idx-2,cost,dp)+cost[idx-2];
        return dp[idx]=min(op1,op2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return help(cost.size(),cost,dp);    
    }
};
