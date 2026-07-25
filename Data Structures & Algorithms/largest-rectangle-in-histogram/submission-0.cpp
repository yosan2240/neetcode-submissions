class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /* Use monotonic stack to determine the fartest smaller element's position */
        stack<int> st;
        stack<int> st2;
        int size = heights.size();
        vector<int> leftSmaller(size, -1);   // index of first smaller bar to the left
        vector<int> rightSmaller(size, size);   // index of first smaller bar to the right
        int result = 0;
        
        /* Get the fartest smaller element's position for both direction */
        for(int i = 0; i < size; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]){
                rightSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);    
        }

        for(int i = size - 1; i >= 0; i--) {
            while(!st2.empty() && heights[i] < heights[st2.top()]){
                leftSmaller[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);    
        }

        /* Calculate the areas and return the maximal one */
        for(int i = 0; i < size; i++) {
            int area = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);
            result = max(result, area);
        }

        return result;
    }
};
