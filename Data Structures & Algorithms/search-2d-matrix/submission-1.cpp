class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int top = 0, bot = ROW - 1;
        while (top<=bot) {
            int row = top + (bot-top)/2;
            if (target > matrix[row][COL-1]) top = row+1;
            else if (target < matrix[row][0]) bot = row-1;
            else break; 
        }
        if (top>bot) return false;
        int l = 0, r = COL-1;
        int row = top + (bot-top)/2;

        while (l<=r) {
            int m = l + (r-l)/2;
            if (target > matrix[row][m]) l=m+1;
            else if (target < matrix[row][m]) r=m-1;
            else return true;
        }
        return false;
    }
};
