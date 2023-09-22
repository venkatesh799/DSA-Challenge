class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        int dir = 0;
        vector<int> spiralOrder;
        while(top <= bottom && left <= right) {
            if(dir == 0) {
                for(int i = left; i <= right; i++) {
                    spiralOrder.push_back(matrix[top][i]);
                }
                top++;
                dir = 1;
            }
            else if(dir == 1) {
                for(int i = top; i <= bottom; i++) {
                    spiralOrder.push_back(matrix[i][right]);
                }
                dir = 2;
                right--;
            }
            else if(dir == 2) {
                for(int i = right; i >= left; i--) {
                    spiralOrder.push_back(matrix[bottom][i]);
                }
                dir = 3;
                bottom--;
            }
            else if(dir == 3) {
                for(int i = bottom; i >= top; i--) {
                    spiralOrder.push_back(matrix[i][left]);
                }
                dir = 0;
                left++;
            }
        }
        return spiralOrder;
    }
};
