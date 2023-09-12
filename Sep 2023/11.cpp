// this is leetcode daily challenge of 12 Sept 2023
// problem link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> v;
        for(auto it:mp)
        {
            int sz=it.first;
            vector<int> arr=it.second;
            int cnt=0;

            for(auto it:arr)
            {
                v.push_back(it);
                cnt++;

                if(cnt%sz==0)
                {
                    ans.push_back(v);
                    v.clear();
                }
            }
        }

        return ans;
    }
};
