// this is leetcode daily challenge of 21 Aug 2023
// problem link : https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        if(t.substr(1,t.size()-2).find(s)!=-1)
            return true;
        return false;
    }
};
