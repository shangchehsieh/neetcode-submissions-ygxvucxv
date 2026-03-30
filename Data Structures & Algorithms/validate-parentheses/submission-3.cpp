class Solution {
public:
    bool isValid(string s) {
        //build stack
        stack<char> stack;
        //dictionary: key(right), value(left)
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (char c : s) {
            if (closeToOpen.count(c)) { //if the key 'c' is ([{
                 
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop(); //if match a pair () [] {}
                } else {
                    return false;
                }
            } else { // if the key 'c' is )]} -> store in stack
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
