class MinStack {
public:
    stack<int> st;    // main stack storing all values
    stack<int> order; // auxiliary stack tracking minimums in order

    MinStack() {}

    void push(int val) {
        st.push(val);
        // only track val as a new minimum if it's <= current minimum
        // using >= ensures duplicate minimums are handled correctly on pop
        if (order.empty() || order.top() >= val)
            order.push(val);
    }

    void pop() {
        // if the element being removed is the current minimum, update order stack
        if (order.top() == st.top())
            order.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        // top of order stack is always the current minimum
        return order.top();
    }
};