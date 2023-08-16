// this is leetcode daily challenge of 16 July 2023
// problem link : https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int i=0,j=0;
        vector<int> ans;
        while(j<nums.size())
        {
            while(!d.empty()&&d.back()<nums[j])
                d.pop_back();
            d.push_back(nums[j]);

            if(j-i+1<k)
                j++;
            else 
            {
                ans.push_back(d.front());
                if(nums[i]==d.front())
                    d.pop_front();
                i++;
                j++;
            }
        }

        return ans;
    }
};
