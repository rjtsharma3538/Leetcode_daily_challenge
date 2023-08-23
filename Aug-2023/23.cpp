// this is leetcode daily challenge of 23 Aug 2023
// problem link : https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        
        string res="";
        while(pq.size()>1)
        {
            auto it1=pq.top();
            pq.pop();
            auto it2=pq.top();
            pq.pop();
            res+=it1.second;
            res+=it2.second;

            it1.first--;
            if(it1.first>0)
                pq.push(it1);
            it2.first--;
            if(it2.first>0)
                pq.push(it2);
        }

        if(pq.empty())
            return res;
        if(pq.top().first>1)
            return "";
        if(res.empty())
        {
            res+=pq.top().second;
            return res;
        }
        if(res.back()!=pq.top().second)
        {
            res+=pq.top().second;
            return res;
        }
        return "";
    }
};
