// this is leetcode daily challenge of 14 Oct 2023
// problem link : https://leetcode.com/problems/painting-the-walls/description/?envType=daily-question&envId=2023-10-14

class Solution {
public:

    int help(int idx, int walls, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if(walls<=0)
            return 0;
        if(idx<0)
            return 1e9;
        if(dp[idx][walls]!=-1)
            return dp[idx][walls];
        int op1=1e9,op2=1e9;
        op1=help(idx-1,walls,cost,time,dp);
        op2=cost[idx]+help(idx-1,walls-time[idx]-1,cost,time,dp);

        return dp[idx][walls]=min(op1,op2);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return help(n-1,n,cost,time,dp);    
    }
};

