// this is leetcode daily challenge of 7 Oct 2023
// problem link : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/?envType=daily-question&envId=2023-10-07

class Solution {
public:

    int mod=1e9+7;

    int help(int n, int m, int k, int maxi, int sz, vector<vector<vector<int>>> &dp)
    {
        //cout<<n<<" "<<m<<" "<<k<<endl;
        if(n==sz)
        {
            if(k==0)
                return dp[n][m][k]=1;
            return dp[n][m][k]=0;
        }

        if(dp[n][m][k]!=-1)
            return dp[n][m][k];

        int cnt=0;

        for(int i=1;i<=m;i++)
        {
            cnt=(cnt+help(n+1,m,k,maxi,sz,dp))%mod;
        }

        if(k>0)
        {
            for(int i=m+1;i<=maxi;i++)
                cnt=(cnt+help(n+1,i,k-1,maxi,sz,dp))%mod;
        }

        //cout<<n<<" "<<m<<" "<<k<<endl;
        return dp[n][m][k]=cnt;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (k+1,-1)));
        return help(0,0,k,m,n,dp);
    }
};
