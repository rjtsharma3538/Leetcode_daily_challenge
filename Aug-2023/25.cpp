// this is leetcode daily challenge of 25 Aug 2023
// problem link : https://leetcode.com/problems/interleaving-string/

class Solution {
public:

    int help(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
    {
        if(k==0)
            return dp[i][j]=true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i==0)
        {
            if(s2[j-1]==s3[k-1])
                return dp[i][j]=help(i,j-1,k-1,s1,s2,s3,dp);
            return dp[i][j]=false;
        }

        if(j==0)
        {
            if(s1[i-1]==s3[k-1])
                return dp[i][j]=help(i-1,j,k-1,s1,s2,s3,dp);
            return dp[i][j]=false;
        }

        if(s1[i-1]!=s3[k-1]&&s2[j-1]!=s3[k-1])
            return dp[i][j]=false;
        
        bool ans=false;

        if(s1[i-1]==s3[k-1])
            ans=ans|help(i-1,j,k-1,s1,s2,s3,dp);
        if(s2[j-1]==s3[k-1])
            ans=ans|help(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i][j]=ans;

    }

    bool isInterleave(string s1, string s2, string s3) {

        int n,m,p;
        n=s1.size();
        m=s2.size();
        p=s3.size();

        if(n+m!=p)
            return false;

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return help(n,m,p,s1,s2,s3,dp);    
    }
};
