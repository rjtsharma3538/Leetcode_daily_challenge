// this is leetcode daily challenge of 13 Nov 2023
// problem link : https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2023-11-13

class Solution {
public:

    bool isvowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }

    string sortVowels(string s) {
        string tmp="";
        for(auto it:s)
        {
            if(isvowel(it))
                tmp+=it;
        } 

        sort(tmp.begin(),tmp.end());
        int j=0;

        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                s[i]=tmp[j++];
            }
        }

        return s;
    }
};
