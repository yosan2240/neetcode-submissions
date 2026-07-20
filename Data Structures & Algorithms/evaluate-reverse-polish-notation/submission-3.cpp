class Solution {
public:
    /*  We need to use the two most recently seen operands to perform the 
    operation; therefore, we use a stack instead of other structures. */
    stack<int> st;

    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            int operand_l, operand_r;
            // note: right operand is popped first since stack is LIFO
            if (tokens[i] == "+") {
                operand_r = topnpop();
                operand_l = topnpop();
                st.push(operand_l + operand_r);
            }
            else if (tokens[i] == "-") {
                operand_r = topnpop();
                operand_l = topnpop();
                st.push(operand_l - operand_r);
            }
            else if (tokens[i] == "*") {
                operand_r = topnpop();
                operand_l = topnpop();
                st.push(operand_l * operand_r);
            }
            else if (tokens[i] == "/") {
                operand_r = topnpop();
                operand_l = topnpop();
                st.push(operand_l / operand_r); // truncates toward zero by default in C++
            }
            else {
                // token is a number — convert and push onto stack
                st.push(stoi(tokens[i]));
            }
        }
        // final result is the only remaining element on the stack
        return st.top();
    }

    // helper: return top element and pop it in one call
    int topnpop() {
        int operand = st.top();
        st.pop();
        return operand;
    }
};