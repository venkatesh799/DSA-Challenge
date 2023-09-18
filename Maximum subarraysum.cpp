class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0;
        int Max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(currMax+nums[i] > nums[i]) {
                currMax += nums[i];
            }
            else {
                currMax = nums[i];
            }
            Max = max(currMax, Max);
        }
        return Max;
    }
};
