// this is leetcode daily challenge of 4 Aug 2023
// problem link : https://leetcode.com/problems/word-break/description/

class Solution {
public:

    bool help(int idx, string &s, set<string> &st, string res, vector<int> &dp)
    {
        if(idx==s.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i=idx;i<s.size();i++)
        {
            res+=s[i];
            if(st.find(res)!=st.end())
            {
                if(help(i+1,s,st,"",dp))
                    return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        vector<int> dp(s.size(),-1);
        return help(0,s,st,"",dp);
    }
}; 
