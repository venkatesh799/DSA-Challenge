/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
  */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length=nums.size();
        for(int i=0; i<length; i++) {
            int x = nums[i];
            nums[i] = 0;
            while(true) {
                if(x < 1 || x > length || x == nums[x -1]) break;
                int y = nums[x-1];
                nums[x-1] = x;
                x = y;
            }
        }
        for(int i=0; i<length; i++) {
            if(nums[i] == 0) return i+1;
        } 
        return length+1; 
    }
};
