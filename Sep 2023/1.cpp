// this is leetcode daily challenge of 2 Sept 2023
// problem link : https://leetcode.com/problems/counting-bits/

class Solution {
public:
    int count(int num)
    {
        int cnt=0;
        while(num)
        {
            if(num&1)
                cnt++;
            num=num>>1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(count(i));
        }

        return ans;
    }
};
