// this is gfg problem of the day of 16 Nov 2023
// problem link : https://leetcode.com/problems/find-unique-binary-string/editorial/?envType=daily-question&envId=2023-11-16

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][i]=='0')
                ans+='1';
            else 
                ans+='0';
        }

        return ans;
    }
};
