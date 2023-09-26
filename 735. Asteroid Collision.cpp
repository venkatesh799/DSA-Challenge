class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> space;
        for(int &element: asteroids) {
            while(!space.empty() && element < 0 && space.top() > 0) {
                int sum = space.top() + element;

                // collision happens --> positive win
                if(sum > 0) {
                    element = 0;
                }
                // collision happened --> Negative win
                else if(sum < 0) {
                    space.pop();
                }
                // same strength i.e 0 both destroy
                else {
                    space.pop();
                    element = 0;
                }
            }
            // if not valid collision push into stack
            if(element != 0) {
                space.push(element);
            }
        }
        vector<int> ans(space.size());
        for(int i=space.size()-1; i>=0; i--) {
            ans[i] = space.top();
            space.pop();
        }
        return ans;
    }
};
