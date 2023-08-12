// this is leetcode daily challenge of 11 Aug 2023
// problem link: https://leetcode.com/problems/coin-change-ii/

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int idx=0;idx<n;idx++)
        {
            for(int target=0;target<=amount;target++)
            {
                if(idx==0)
                {
                    if(target%coins[idx]==0)
                        dp[idx][target]=1;
                    else 
                        dp[idx][target]=0;
                }

                else 
                {
                    int op1=0,op2=0;
                    if(coins[idx]<=target)
                        op1=dp[idx][target-coins[idx]];
                    op2=dp[idx-1][target];

                    dp[idx][target]=op1+op2;
                }
            }
        }
        return dp[n-1][amount];
    }
};
