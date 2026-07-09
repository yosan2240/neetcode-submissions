class Solution {
public:
    int trap(vector<int>& height) {
        /* Time: O(n), Space: O(n), It still has room to be optimized*/
        int result = 0;
        vector<int> leftMax(height.size(), 0), rightMax(height.size(), 0);
        int temp = 0;
        for (int i = 1; i < height.size(); i++) {
            temp = max(temp, height[i - 1]);
            leftMax[i] = temp;
            cout << leftMax[i] ;
        }
        cout << endl;

        temp = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            temp = max(temp, height[i + 1]);
            rightMax[i] = temp;
            cout << rightMax[i] ;
        }
        cout << endl;

        for (int i = 0; i < height.size(); i++) {
            int maxfromleft = leftMax[i];
            int maxfromright = rightMax[i];
            int amount = min(maxfromleft, maxfromright) - height[i];
            if (amount > 0)
                result += amount;
        }

        return result;
    }
};
