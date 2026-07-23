class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic decreasing stack — stores indices of days still waiting for a warmer day
        stack<int> st;
        int size = temperatures.size();
        vector<int> result(size, 0); // default 0: no warmer day found

        st.push(0); // start with the first day

        for (int j = 1; j < size; j++) {
            // current day is warmer than days on the stack — resolve their answers
            while (!st.empty() &&
                   temperatures[st.top()] < temperatures[j]) {
                result[st.top()] = j - st.top(); // number of days to wait
                st.pop();
            }
            // current day is now waiting for its own warmer day
            st.push(j);
        }

        return result;
    }
};