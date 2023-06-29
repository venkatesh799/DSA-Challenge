// Problem Link: https://leetcode.com/problems/two-sum/description/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++) {
            if(dict.find(target-nums[i]) != dict.end()) {
                ans.push_back(i);
                ans.push_back(dict[target-nums[i]]);
            }
            else {
                dict[nums[i]] = i;
            }
        }
        return ans;
    }
};
