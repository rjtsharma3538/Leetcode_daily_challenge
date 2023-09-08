// this is leetcode daily challenge of 9 Sept 2023
// problem link : https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2023-09-08

class Solution {
public:

    vector<int> generate_row(int row)
    {
        int ans=1;
        vector<int> v;
        v.push_back(1);

        for(int col=1;col<row;col++)
        {
            ans=ans*(row-col);
            ans=ans/col;
            v.push_back(ans);
        }

        return v;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> v=generate_row(i);
            ans.push_back(v);
        }    

        return ans;
    }
};
