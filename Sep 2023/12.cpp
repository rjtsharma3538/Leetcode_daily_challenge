// this is leetcode daily challenge of 12 Sept 2023
// problem link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/?envType=daily-question&envId=2023-09-12

class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        int maxi=0;
        for(auto it:s)
        {
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }

        map<int,int> m;
        vector<int> v;
        for(auto it:mp)
        {
            m[-it.second]++;
            v.push_back(it.second);
        }
        
        stack<int> st;
        for(int i=1;i<=maxi;i++)
        {
            if(m.find(-i)==m.end())
                st.push(i);
        }

        int ans=0;
        set<int> stt;
        sort(v.rbegin(),v.rend());
        for(auto it:v)
        {
            int freq=it;
            cout<<freq<<endl;
            if(stt.find(freq)==stt.end())
            {
                stt.insert(freq);
            }
            else 
            {
                while(!st.empty()&&st.top()>freq)
                    st.pop();
                if(st.empty())
                    ans+=freq;
                else 
                {
                    ans+=freq-st.top();
                    st.pop();
                }
            }
        }

        return ans;
    }
};
