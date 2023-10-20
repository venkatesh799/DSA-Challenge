/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowhaszero = false, colhaszero = false;
        int row = matrix.size(), col = matrix[0].size();

        // check for first row has any zero
        for(int r=0; r<row; r++) {
            if(matrix[r][0] == 0) {
                colhaszero = true;
                break;
            }
        }

        // check for first row has any zero
        for(int c=0; c<col; c++) {
            if(matrix[0][c] == 0) {
                rowhaszero = true;
                break;
            }
        }

        // check for zeros in matrix and mark them in first row and first col.
        for(int r=1; r<row; r++) {
            for(int c=1; c<col; c++) {
                if(matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // filling matrix with zeros.
        for(int r=1; r<row; r++) {
            for(int c=1; c<col; c++) {
                if(matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Handle the first row and first column if they have zeroes
        if (rowhaszero) {
            for (int c = 0; c < col; c++) {
                matrix[0][c] = 0;
            }
        }

        if (colhaszero) {
            for (int r = 0; r < row; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};
