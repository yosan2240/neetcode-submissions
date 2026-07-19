class MinStack {
public:
    stack<int> st;
    stack<int> order;
    MinStack() {
        return;
    }
    
    void push(int val) {
        st.push(val);
        if(order.empty() || order.top() >= val)
            order.push(val);
    }
    
    void pop() {
        if(order.top() == st.top())
            order.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return order.top();
    }
};
