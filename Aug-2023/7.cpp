// this is leetcode daily challenge of 7 Aug 2023
// problem link : https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n,m;
        n=matrix.size();
        m=matrix[0].size();

        int i,j;
        i=0;
        j=m-1;

        while(i<n&&j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target)
                i++;
            else 
                j--;
        }

        return false;
    }
};
