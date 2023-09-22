// this is leetcode daily challenge of 22 Sept 2023
// problem link : https://leetcode.com/problems/is-subsequence/description/?envType=daily-question&envId=2023-09-22

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)
            return true;
        int i=0;
        for(int j=0;j<t.size();j++)
        {
            if(s[i]==t[j])
                i++;
            if(i==s.size())
                return true;
        }
        return false;
    }
};
