// this is leetcode daily challenge of 27 Aug 2023
// problem link : https://leetcode.com/problems/frog-jump/description/

class Solution {
public:

    bool help(int idx, int k, vector<int> &stones, vector<vector<int>> &dp)
    {
        if(idx==stones.size()-1)
            return true;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];

        bool op1=false,op2=false,op3=false;

        int val,ind;

        val=stones[idx]+k+1;
        ind=lower_bound(stones.begin(),stones.end(),val)-stones.begin();
        if(ind<stones.size()&&stones[ind]==val)
            op1=help(ind,k+1,stones,dp);
        
        val=stones[idx]+k;
        ind=lower_bound(stones.begin(),stones.end(),val)-stones.begin();
        if(ind<stones.size()&&stones[ind]==val)
            op2=help(ind,k,stones,dp);
        
        if(k-1>0)
        {
            val=stones[idx]+k-1;
            ind=lower_bound(stones.begin(),stones.end(),val)-stones.begin();
            if(ind<stones.size()&&stones[ind]==val)
                op3=help(ind,k-1,stones,dp);
        }
        
        return dp[idx][k]=op1|op2|op3;

    }

    bool canCross(vector<int>& stones) {
        int val,ind;
        val=stones[0]+1;
        ind=lower_bound(stones.begin(),stones.end(),val)-stones.begin();
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        if(ind<stones.size()&&stones[ind]==val)
            return help(ind,1,stones,dp);
        return false;
    }
};
