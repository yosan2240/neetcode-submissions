class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequency array with offset 1000
        vector<pair<int,int>> frequency(2001);
        for (int i = 0; i < 2001; i++)
            // {實際數值, 頻率}
            frequency[i] = {i - 1000, 0};  

        // build frequencies
        for (int num : nums) 
            frequency[num + 1000].second++;   

        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, cnt] : frequency) 
            buckets[cnt].push_back(num);

        vector<int> result;
        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
            for (int num : buckets[i])
                result.push_back(num);
        }
        return result;
    }
};
