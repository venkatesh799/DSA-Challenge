// Problem link:  https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    // fun to check for the last unclosed, first closed
    bool check(char open, char close) {
        if(open == '{' && close == '}') return true;
        else if(open == '(' && close == ')') return true;
        else if(open == '[' && close == ']') return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> stack_list;
        for(int i = 0; i < s.length(); i++) {
            // check for open element
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                // push the element into the stack
                stack_list.push(s[i]);
            }
            // check for closed element
            else if(s[i] == '}' || s[i] == ')' || s[i] == ']') {
                // if the stack empty and if we got closed then it is false
                // if stack not empty just check for the counter element for current elememt
                if(stack_list.empty() || !check(stack_list.top(), s[i])) {
                    return false;
                }
                // if we find the counter part of current element just pop the top element from stack
                else {
                    stack_list.pop();
                }
            }
        }
        return stack_list.empty() ? true: false;
    }
};
