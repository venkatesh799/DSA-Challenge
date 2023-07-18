/*

Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:
Input:
  N = 5
  A[] = {1,2,3,5}
Output: 4

Example 2:
Input:
  N = 10
  A[] = {6,1,2,8,3,4,7,10,5}
Output: 9

Problem: https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Method1: hash map( Time & space wasted)
Method2: sum on natural number - sum of given array ( linear time and constant space but there is a value overflow posibility)
Method3: XOR
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        // Using XOR 
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            ans ^= array[i];
        }
        for(int i = 1; i <= n; i++) {
            ans ^= i;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*

  TIME COMPLEXITY 

Since both loops have a linear relationship with the input size n, the time complexity of each loop is O(n). However, they are sequential, meaning that one loop is executed after the other. Therefore, we need to consider their combined time complexity.

Since the two loops are not nested within each other, the time complexity of the entire function is the sum of the time complexities of both loops, which results in O(n) + O(n) = O(2n).

However, in big O notation, we drop constant factors, so the overall time complexity of the given function is O(n).

*/
