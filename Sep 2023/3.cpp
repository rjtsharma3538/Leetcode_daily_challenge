/// this is leetcode daily challenge of 3 Sept 2023
// problem link : https://leetcode.com/problems/unique-paths/description/?envType=daily-question&envId=2023-09-03

class Solution {
public:
    int help(int m, int n, vector<vector<int>> &dp)
    {
        if(m==0)
            return dp[m][n]=1;
        if(n==0)
            return dp[m][n]=1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int op1=help(m-1,n,dp);
        int op2=help(m,n-1,dp);

        return dp[m][n]=op1+op2;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return help(m-1,n-1,dp);    
    }
};
