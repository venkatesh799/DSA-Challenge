class Solution {
public:
    int climbStairs(int n) {

    // Method 1
       int way1 = 1, way2 = 1;
       for(int i = 0; i < n - 1; i++) {
           int ways;
           ways = way1 + way2;
           way1 = way2;
           way2 = ways;
       } 
       return way2;

    // Method2: DP
    // vector<int> ways(n+1);
    // ways[0] = 1;
    // ways[1] = 1;
    // for(int i = 2; i <= n; i++) {
    //     ways[i] = ways[i-1] + ways[i-2];
    // }
    // return ways[n];
    }
};
