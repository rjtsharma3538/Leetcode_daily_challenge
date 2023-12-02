// this is leetcode daily challenge of 2 Dec 2023
// problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        for(auto it:chars)
            mp[it]++;
        
        int ans=0;
        for(auto s:words)
        {
            map<char,int> mp1=mp;
            bool f=1;
            for(auto it:s)
            {
                if(mp1.find(it)!=mp1.end())
                {
                    mp1[it]--;
                    if(mp1[it]==0)
                        mp1.erase(it);
                }
                else 
                {
                    f=0;
                    break;
                }
            }

            if(f)
                ans+=s.size();
        }

        return ans;

    }
};
