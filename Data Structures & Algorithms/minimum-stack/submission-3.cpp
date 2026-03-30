class MinStack {
public:
    std::stack<int> stack, minStack;
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
