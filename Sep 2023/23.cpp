// this is leetcode daily challenge of 23 Sept 2023
// problem link : https://leetcode.com/problems/longest-string-chain/description/?envType=daily-question&envId=2023-09-23

class Solution {
public:

    static bool compare(string s1,string s2)
    {
        return s1.size()<s2.size();
    }

    bool check(string p,string q)
    {
        int i=0,j=0,cnt=0;
        while(i<p.size()&&j<q.size())
        {
            if(p[i]==q[j])
            {
                i++;
                j++;
            }
            else 
            {
                cnt++;
                i++;
            }
            if(cnt>1)
                return false;
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), compare);
        vector<int> dp(n,1);
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            string p=words[i];
            for(int j=0;j<i;j++)
            {
                string q=words[j];
                if(p.size()==q.size()+1)
                {
                    if(check(p,q))
                        dp[i]=max(dp[i],1+dp[j]);  
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};
