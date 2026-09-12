class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char ,int> freq_table;    // Record the frequency of tasks
        // To pick the most frequent ready task, we don't care which task it is
        priority_queue<int> pq; 
        queue<pair<int,int>> q; // Check if the task is ready

        // Count the frequency of each tasks 
        for(auto& task : tasks) {
            freq_table[task]++;
        }

        for(auto freq : freq_table) {
            pq.push(freq.second);
        }
        
        int cycle = 0;
        while(!pq.empty() || !q.empty()) {
            if(!q.empty()) {
                if(q.front().second < cycle){
                    pq.push(q.front().first);
                    q.pop();
                }
            }

            if(!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                if(temp - 1 > 0)
                    q.push({temp - 1, cycle + n});
            }
            cycle++;
        }

        return cycle;
    }
};

