// this is leetcode daily challenge of 2 Sept 2023
// problem link : https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02

class Solution {
public:
    
    int help(int idx, string &s, set<string> &st, vector<int> &dp)
    {
        if(idx==s.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        string res="";
        int cnt=0,mini=INT_MAX;
        for(int i=idx;i<s.size();i++)
        {
            res+=s[i];
            if(st.find(res)!=st.end())
                mini=min(mini,help(i+1,s,st,dp));
            else 
                mini=min(mini,i-idx+1+help(i+1,s,st,dp));
        }
        return dp[idx]=mini;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        for(auto it:dictionary)
            st.insert(it);
        
        vector<int> dp(s.size(),-1);
        return help(0,s,st,dp);
    }
};
