// this is leetcode daily challenge of 26 Sept 2023
// problem link : https://leetcode.com/problems/remove-duplicate-letters/submissions/?envType=daily-question&envId=2023-09-26

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]=i;
        
        stack<char> stk;
        set<char> st;
        string res="";

        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])==st.end())
            {
                while(!stk.empty()&&s[i]<stk.top()&&i<mp[stk.top()])
                {
                    st.erase(stk.top());
                    stk.pop();
                }
                stk.push(s[i]);
                st.insert(s[i]);
            }
        }

        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
