/*
For an integer N find the number of trailing zeroes in N!.
Example 1:
Input:
N = 5
Output:
1
Explanation:
5! = 120 so the number of trailing zero is 1.
*/

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int ans = 0;
        if(N < 0) {
            return -1;
        }
        for(int i = 5; N/i >= 1; i = i * 5) {
            ans = ans + N/i;
        }
        return ans;
    }
};
