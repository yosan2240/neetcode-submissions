class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        return;
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vec = map[key];
        int l = 0, r = vec.size() - 1;
        int timestamp_prev = INT_MIN;
        string result = "";
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(vec[mid].first <= timestamp){
                l = mid + 1;
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
