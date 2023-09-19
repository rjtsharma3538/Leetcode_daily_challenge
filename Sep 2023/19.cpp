// this is leetcode daily challenge of 19 Sept 2023
// problem link : https://leetcode.com/problems/find-the-duplicate-number/submissions/?envType=daily-question&envId=2023-09-19

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int x;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                x=nums[i];
                break;
            }
            st.insert(nums[i]);
        }
        return x;
    }
};
