// this is leetcode daily challenge of 3 Aug 2023
// problem link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:

    void help(string digits, int idx, string &s, vector<string> &ans, map<char,string> &mp)
    {
        if(idx==digits.size())
        {
            if(s.size()!=0)
                ans.push_back(s);
            return;
        }

        for(int i=0;i<mp[digits[idx]].size();i++)
        {
            s+=mp[digits[idx]][i];
            help(digits,idx+1,s,ans,mp);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string s="";
        vector<string> ans;
        help(digits,0,s,ans,mp);
        return ans;
    }
};
