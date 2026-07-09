class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            int counts[26] = {0};
            for (char c : s)
                counts[c - 'a']++;
            
            /* build key for hash table */
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(counts[i]);
                /*  delimiter to avoid ambiguity, The # delimiter 
                    is important — without it, counts like [1,23] 
                    and [12,3] would both produce "123" and be 
                    incorrectly grouped together. 
                */
                key += '#';
            }
            /*  vector insert only inserts when the key does not exist. 
                If the key already exists, it does nothing. 
            */
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& p : groups) {
            result.push_back(p.second);
        }
        return result;

    }
};
