/*

You are given an m x n integer matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1;
        while(row < matrix.size() && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(target < matrix[row][col]) {
                col = col-1;
            }
            else{
                row = row+1;
            }
        }
        return false;
    }
};
