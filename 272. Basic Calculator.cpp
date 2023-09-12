// 272. Basic Calculator
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0;
        int curr_num = 0;
        char sign = '+';
        int length = s.size();
        for(int i = 0; i < length; i++) {
            if(isdigit(s[i])) {
                curr_num = curr_num*10 + (s[i] - '0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == length - 1) {
                if(sign == '+') {
                    stk.push(curr_num);
                }
                else if(sign == '-') {
                    stk.push(-curr_num);
                }
                else {
                    int num = 0;
                    if(sign == '*') {
                        num = stk.top() * curr_num;
                    }
                    else {
                        num = stk.top() / curr_num;
                    }   
                    stk.pop();
                    stk.push(num);
                }
                curr_num = 0;
                sign = s[i];
            }
        }
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};


/*
  
Time Complexity: O(n)
Space Complexity: O(n) in the worst case, but potentially less if there are spaces in the input string.
*/
