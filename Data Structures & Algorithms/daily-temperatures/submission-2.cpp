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

/* DP solution is O(n^2) in time complexity in worst case
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); // 0 means no warmer day found

        // traverse right to left, reusing previously computed answers
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1; // start checking from the next day

            // jump forward using res[j] until we find a warmer day or exhaust options
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (res[j] == 0) {
                    // day j has no warmer day ahead — no answer for i either
                    j = n;
                    break;
                }
                // day j is not warmer, but we know the next warmer day for j
                // jump directly there instead of checking one by one
                j += res[j];
            }

            if (j < n) {
                // found a warmer day at index j
                res[i] = j - i;
            }
        }
        return res;
    }
};
*/