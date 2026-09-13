class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task using a fixed-size array (A=0, Z=25)
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        // Sort so the highest frequency is at the end
        sort(count.begin(), count.end());
        int maxf = count[25]; // The maximum frequency among all tasks

        // Start with the maximum possible idle slots
        int idle = (maxf - 1) * n;

        // Fill idle slots with other tasks
        // Each task can fill at most (maxf - 1) slots (aligned with the most frequent task)
        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, count[i]);
        }

        // If idle < 0, all idle slots are filled — answer is just tasks.size()
        // Otherwise, add remaining idle slots to total tasks
        return max(0, idle) + (int)tasks.size();
    }
};