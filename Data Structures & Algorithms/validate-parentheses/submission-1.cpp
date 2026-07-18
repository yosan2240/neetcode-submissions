class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {
            // push all opening brackets
            if(ch == '{' || ch == '(' || ch == '[')
                st.push(ch);
            else {
                // closing bracket with empty stack — no matching opener
                if(st.empty())
                    return false;
                // check if top matches the current closing bracket
                else if (ch == ')' && st.top() != '(') 
                    return false;
                else if (ch == ']' && st.top() != '[') 
                    return false;
                else if (ch == '}' && st.top() != '{') 
                    return false;
                st.pop();
            }
        }

        // unmatched opening brackets remaining
        return st.empty() ? true : false;
    }
};
