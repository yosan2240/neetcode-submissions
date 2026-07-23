class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
        int i = 0, j = 1;
        vector<int> result(size, 0);

        st.push(0);

        while(j < size) {
            while(!st.empty() &&
                temperatures[st.top()] < temperatures[j]) {
                result[st.top()] = j - st.top();
                st.pop();
                i++;
            }
            st.push(j);
            j++;
            
        }

        return result;
    }
};
