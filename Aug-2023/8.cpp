// this is leetcode daily challenge of 8 Aug 2023
// problem link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int s=0,e=nums.size()-1;

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[s]<=nums[mid])
            {
                if(nums[s]<=target&&target<=nums[mid])
                    e=mid-1;
                else 
                    s=mid+1;
            }
            else if(nums[mid]<=nums[e])
            {
                if(nums[mid]<=target&&target<=nums[e])
                    s=mid+1;
                else 
                    e=mid-1;
            }
        }

        return -1;
    }
};
