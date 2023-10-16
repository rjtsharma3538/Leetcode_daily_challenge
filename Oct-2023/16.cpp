// this is leetcode daily challenge of 16 Oct 2023
// problem link : https://leetcode.com/problems/pascals-triangle-ii/description/?envType=daily-question&envId=2023-10-16

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev={1};

        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> curr(i+1);
            curr[0]=1;
            curr[i]=1;

            for(int j=1;j<i;j++)
                curr[j]=prev[j]+prev[j-1];
            prev=curr;
        }

        return prev;
    }
};
