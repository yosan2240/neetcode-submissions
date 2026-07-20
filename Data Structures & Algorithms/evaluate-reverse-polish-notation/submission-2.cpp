class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        for(int i = 0; i < tokens.size(); i++) {
            int operand_l, operand_r;
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
                st.push(operand_l / operand_r);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }

    int topnpop(void) {
        int operand = st.top();
        st.pop();

        return operand;
    }
};
