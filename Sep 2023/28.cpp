// this is leetcode daily challenge of 28 Sept 2023
// problem link : https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2023-09-28

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]%2)
            {
                swap(nums[i],nums[j]);
                j--;
            }
            else 
                i++;
        }

        return nums;
    }
};
