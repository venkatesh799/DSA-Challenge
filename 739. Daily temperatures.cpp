/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
  
Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int, int>> st;
       vector<int> res(temperatures.size(), 0);
       int n = temperatures.size()-1;
       res[n] = 0;
       st.push({temperatures[n], n});
       for(int i=n; i>=0; i--) {
           while(!st.empty() && temperatures[i] >= st.top().first) {
               st.pop();
           }
           if(!st.empty()) {
               res[i] = st.top().second - i;
           }
           st.push({temperatures[i], i});
       }
        return res;
    }
};
