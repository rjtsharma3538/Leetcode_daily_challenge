// this is leetcode daily challenge of 29 Sept 2023
// problem link : https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i=1;
        bool f;
        while(i<nums.size())
        {
            if(nums[i-1]<nums[i])
            {
                f=1;
                break;
            }
            else if(nums[i-1]>nums[i])
            {
                f=0;
                break;
            }
            i++;
        }

        i++;
        while(i<nums.size())
        {
            if(f==0&&nums[i-1]<nums[i])
                return false;
            else if(f==1&&nums[i-1]>nums[i])
                return false;
            i++;
        }
        return true;
    }
};
