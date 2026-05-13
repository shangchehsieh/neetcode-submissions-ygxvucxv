class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left < right) {
            int top = left;
            int bottom = right;
            
            for (int i = 0; i< right-left; i++) {
                // save top left
                int topLeft = matrix[top][left + i];
                // bottom left -> top left
                matrix[top][left + i] = matrix[bottom - i][left];
                // bottom right -> bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];
                // top right -> bottom right
                matrix[bottom][right - i] = matrix[top + i][right];
                // top left -> top right
                matrix[top + i][right] = topLeft;
            }
            right -= 1;
            left += 1;
            
        }
    }
};
