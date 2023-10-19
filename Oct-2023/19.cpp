// this is leetcode daily challenge of 19 Oct 2023
// problem link : https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19

class Solution {
public:

    string help(string s)
    {
        stack<char> st;
        for(auto it:s)
        {
            if(st.empty()&&it!='#')
                st.push(it);
            else if(it=='#')
            {
                if(!st.empty())
                    st.pop();
            }
            else 
                st.push(it);
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }

    bool backspaceCompare(string s, string t) {
        s=help(s);
        t=help(t);

        cout<<s<<" "<<t<<endl;

        if(s==t)
            return true;
        return false;    
    }
};
