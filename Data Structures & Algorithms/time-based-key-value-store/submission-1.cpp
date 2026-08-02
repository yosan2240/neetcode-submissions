class TimeMap {
public:
    // maps each key to a list of (timestamp, value) pairs, sorted by timestamp
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // locate the corresponding vector for this key
        auto& vec = map[key];
        int l = 0, r = vec.size() - 1;
        int timestamp_prev = INT_MIN;
        string result = "";

        // binary search for the largest timestamp <= given timestamp
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(vec[mid].first <= timestamp){
                l = mid + 1;
                // update best candidate so far
                if(timestamp_prev < vec[mid].first){
                    result = vec[mid].second;
                    timestamp_prev = vec[mid].first;
                }
            }
            else{
                r = mid - 1;
            }
        }

        return result;
    }
};