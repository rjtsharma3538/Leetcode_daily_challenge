// this is leetcode daily challenge of 6 Oct 2023
// problem link : https://leetcode.com/problems/integer-break/description/?envType=daily-question&envId=2023-10-06

class Solution {
public:

    int help(int n, vector<int> &dp)
    {
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int maxi=1;
        for(int i=1;i<=n;i++)
        {
            if(i<=n)
                maxi=max(maxi,i*help(n-i,dp));
            else 
                break;
        }
        return dp[n]=maxi;
    }

    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        vector<int> dp(n+1,-1);
        return help(n,dp);    
    }
};
