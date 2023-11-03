// this is leetcode daily challenge of 3 Nov 2023
// problem link : https://leetcode.com/problems/build-an-array-with-stack-operations/?envType=daily-question&envId=2023-11-03

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=1,j=0;
        vector<string> v;
        while(i<=n&&j<target.size())
        {
            if(i==target[j])
            {
                v.push_back("Push");
                i++;
                j++;
            }
            else if(i<target[j])
            {
                int cnt=0;
                while(i<target[j])
                {
                    v.push_back("Push");
                    i++;
                    cnt++;
                }

                for(int i=0;i<cnt;i++)
                    v.push_back("Pop");
            }
        }

        return v;
    }
};
