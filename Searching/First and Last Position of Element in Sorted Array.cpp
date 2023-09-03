class Solution {
public:
    int first_index(vector<int> A, int key, int start, int end) {
        int res = -1;
        int mid;
        while(start <= end) {
            mid = (start) + (end - start)/2;
            if(A[mid] == key) {
                res = mid;
                end = mid - 1;
            }
            else if(key > A[mid]) {
                start = mid + 1;
            }
            else if(key < A[mid]) {
                end = mid -1;
            }
        }
        return res;
    }
    int last_index(vector<int> A, int key, int start, int end) {
        int res = -1;
        int mid;
        while(start <= end) {
            mid = (start) + (end - start)/2;
            if(A[mid] == key) {
                res = mid;
                start = mid + 1;
            }
            else if(key > A[mid]) {
                start = mid + 1;
            }
            else if(key < A[mid]) {
                end = mid -1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = first_index(nums, target, 0, nums.size()-1);
        if(result[0] == -1) {
            return result;
        }
        result[1] = last_index(nums, target, 0, nums.size()-1);
        return result;
    }
};
