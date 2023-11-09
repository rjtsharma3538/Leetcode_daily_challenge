// this is leetcode daily challenge of 9 Nov 2023
// problem link : https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09

class Solution {
public:
    int countHomogenous(string s) {
        long long int mod=1e9+7,ans=0;
        long long int cnt=1;
        char c=s[0];

        for(int i=1;i<s.size();i++)
        {
            if(s[i]==c)
                cnt++;
            else 
            {
                long long int tmp=((cnt%mod)*((cnt+1)%mod)/2)%mod;
                ans=(ans+tmp)%mod;
                cnt=1;
                c=s[i];
            }
        }

        long long int tmp=((cnt%mod)*((cnt+1)%mod)/2)%mod;
            ans=(ans+tmp)%mod;
        
        return ans;
    }
};
