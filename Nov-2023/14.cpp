// this is leetcode daily challenge of 14 Nov 2023
// problem link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/solutions/?envType=daily-question&envId=2023-11-14

class Solution {
public:
    bool help(vector<int> &v, int fst, int last)
    {
        int s=0,e=v.size()-1,ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(v[mid]>fst)
            {
                ans=v[mid];
                e=mid-1;
            }
            else 
                s=mid+1;
        }

        if(ans>fst&&ans<last)
            return true;
        return false;
    }

    int countPalindromicSubsequence(string s) {
        int n=s.size();
        map<char,vector<int>> mp;

        for(int i=0;i<n;i++)
            mp[s[i]].push_back(i);
        
        // for(char c='a';c<='z';c++)
        // {
        //     cout<<c<<" ";
        //     if(mp.find(c)!=mp.end())
        //     {
        //         for(auto it:mp[c])
        //             cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans=0;
        
        for(char c='a';c<='z';c++)
        {
            int cnt=0;
            if(mp.find(c)!=mp.end()&&mp[c].size()>=2)
            {
                int fst=mp[c][0];
                int last=mp[c].back();

                for(char c1='a';c1<='z';c1++)
                {
                    if(c1==c)
                    {
                        if(mp[c1].size()>2)
                            cnt++;
                    }
                    else if(mp.find(c1)!=mp.end())
                    {
                        if(help(mp[c1],fst,last))
                            cnt++;
                    }

                    // if(c=='c')
                    //     cout<<c1<<" "<<cnt<<endl;
                }
            }
            ans+=cnt;
            //cout<<c<<" "<<cnt<<endl;
        }

        return ans;
    }
};
