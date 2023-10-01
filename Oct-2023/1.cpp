// this is leetcode daily challenge of 1 Oct 2023
// problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/editorial/?envType=daily-question&envId=2023-10-01

class Solution {
public:
    string reverseWords(string s) {
        string res="",temp="";
        for(auto it:s)
        {
            if(it==' ')
            {
                reverse(temp.begin(),temp.end());
                res+=temp;
                res+=' ';
                temp="";
            }
            else 
                temp+=it;
        }

        reverse(temp.begin(),temp.end());
        if(temp!=" ")
            res+=temp;
        
        return res;
    }
};
