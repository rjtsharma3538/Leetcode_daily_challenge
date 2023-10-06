// this is leetcode daily challenge of 6 Oct 2023
// problem link : https://leetcode.com/problems/majority-element-ii/?envType=daily-question&envId=2023-10-06

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int num1=-1,num2=-1,cnt1=0,cnt2=0;

        for(auto it:nums)
        {
            if(cnt1==0&&it!=num2)
            {
                cnt1++;
                num1=it;
            }
            else if(cnt2==0&&it!=num1)
            {
                cnt2++;
                num2=it;
            }
            else if(it==num1)
                cnt1++;
            else if(it==num2)
                cnt2++;
            else 
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;

        for(auto it:nums)
        {
            if(it==num1)
                cnt1++;
            else if(it==num2)
                cnt2++;
        }

        vector<int> ans;
        if(cnt1>nums.size()/3)
            ans.push_back(num1);
        if(cnt2>nums.size()/3)
            ans.push_back(num2);
        
        return ans;
    }
};
