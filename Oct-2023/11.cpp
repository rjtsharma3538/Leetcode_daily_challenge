// this is leetcode daily challenge of 11 Oct 2023
// problem link : https://leetcode.com/problems/number-of-flowers-in-full-bloom/editorial/?envType=daily-question&envId=2023-10-11

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start,stop;
        for(auto it:flowers)
        {
            start.push_back(it[0]);
            stop.push_back(it[1]);
        }

        sort(start.begin(),start.end());
        sort(stop.begin(),stop.end());
        vector<int> ans;

        for(auto it:people)
        {
            auto idx=upper_bound(start.begin(),start.end(),it)-start.begin();
            auto new_idx=upper_bound(stop.begin(),stop.begin()+idx,it)-stop.begin();
            if(new_idx-1>=0&&stop[new_idx-1]==it)
                new_idx=lower_bound(stop.begin(),stop.begin()+idx,it)-stop.begin();

            cout<<idx<<" "<<new_idx<<endl;

            ans.push_back(idx-new_idx);
        }

        return ans;
    }
};
