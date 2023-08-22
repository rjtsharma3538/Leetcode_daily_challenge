// this is leetcode daily challenge of 22 Aug 2023
// problem link : https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int,char> mp;
        char c='A';
        for(int i=1;i<=25;i++)
        {
            mp[i]=c;
            c++;
        }

        string ans="";
        while(columnNumber)
        {
            int rem=columnNumber%26;
            columnNumber/=26;
            if(rem==0)
            {
                columnNumber--;
                ans+='Z';
            }
            else 
                ans+=mp[rem];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
