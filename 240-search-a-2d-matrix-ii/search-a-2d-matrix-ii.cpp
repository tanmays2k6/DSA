class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=n-1;
        while(col>=0 && row<m){
            if(tar==matrix[row][col]){
                return true;
            }
            else if(tar<matrix[row][col]){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};