// this is leetcode daily challenge of 26 Aug 2023
// problem link : https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
