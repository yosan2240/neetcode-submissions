class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {
            int operand_l, operand_r;
            if (tokens[i] == "+") { 
                operand_r = st.top();
                st.pop();
                operand_l = st.top();
                st.pop();
                st.push(operand_l + operand_r);
            }
            else if (tokens[i] == "-") {
                operand_r = st.top();
                st.pop();
                operand_l = st.top();
                st.pop();
                st.push(operand_l - operand_r);
            }
            else if (tokens[i] == "*") {
                operand_r = st.top();
                st.pop();
                operand_l = st.top();
                st.pop();
                st.push(operand_l * operand_r);
            }
            else if (tokens[i] == "/") {
                operand_r = st.top();
                st.pop();
                operand_l = st.top();
                st.pop();
                st.push(operand_l / operand_r);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
