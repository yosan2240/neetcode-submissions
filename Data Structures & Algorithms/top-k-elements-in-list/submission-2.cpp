class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // freq array with offset 1000
        int frequency[2001] = {0};

        // build frequencies
        for (int num : nums) 
        frequency[num + 1000]++;       

        vector<pair<int,int>> vec;
        // collect unique (value, freq) pairs
        for (int i = 0; i < 2001; i++)                      
            if (frequency[i] > 0) 
                vec.push_back({i - 1000, frequency[i]});

        // partial sort
        nth_element(vec.begin(), vec.begin() + k, vec.end(),  
            [](auto& a, auto& b){ return a.second > b.second; });

        vector<int> result;
        for (int i = 0; i < k; i++) 
            result.push_back(vec[i].first);
            
        return result;
    }
};
