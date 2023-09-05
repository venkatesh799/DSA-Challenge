// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int prev;
        int next;
        int nums_len = nums.size();
        while(low <= high)  {
            if(nums[low] <= nums[high]) {
                return nums[low];
            }
            mid = (low + high)/2;
            next = (mid + 1)%nums_len;
            prev = (mid + nums_len - 1)%nums_len;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                return nums[mid];
            }
            else if(nums[mid] <= nums[high]) {
                high = mid - 1;
            }
            else if(nums[mid] >= nums[low]) {
                low = mid + 1;
            }
        }
        return -1;
    }
};
