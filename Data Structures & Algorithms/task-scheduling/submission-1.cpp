class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq_table;
        priority_queue<int> pq;
        queue<pair<int, int>> q; // {remaining_count, ready_at_cycle}

        // Count the frequency of each task
        for (auto& task : tasks) {
            freq_table[task]++;
        }

        // Push all frequencies into the max heap
        for (auto& freq : freq_table) {
            pq.push(freq.second);
        }

        int cycle = 0;
        // Keep running until all tasks are completed and no tasks are on cooldown
        while (!pq.empty() || !q.empty()) {
            // If the front task in the cooldown queue is ready, move it back to the heap
            if (!q.empty() && q.front().second < cycle) {
                pq.push(q.front().first);
                q.pop();
            }

            // Pick the most frequent available task and execute it
            if (!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                // If the task still has remaining count, put it on cooldown
                if (temp - 1 > 0)
                    q.push({temp - 1, cycle + n});
            }
            // Otherwise this cycle is idle

            cycle++;
        }

        return cycle;
    }
};