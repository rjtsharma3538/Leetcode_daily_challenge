// this is leetcode daily challenge of 15 Oct 2023
// problem link : https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description?envType=daily-question&envId=2023-10-15

class Solution {
public:

    int mod=1e9+7;
    long long int help(int idx, int steps, int arrLen, vector<vector<long long int>> &dp)
    {
        if(steps==0)
        {
            if(idx==0)
                return 1;
            return 0;
        }

        if(idx<0||idx>=arrLen)
            return 0;

        if(dp[idx][steps]!=-1)
            return dp[idx][steps];

        long long int op1=help(idx-1,steps-1,arrLen,dp);
        long long int op2=help(idx,steps-1,arrLen,dp);
        long long int op3=help(idx+1,steps-1,arrLen,dp);

        return dp[idx][steps]=((op1%mod)+(op2%mod)+(op3%mod))%mod;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<long long int>> dp(steps+1,vector<long long int> (steps+1,-1));
        return help(0,steps,arrLen,dp);
    }
};
