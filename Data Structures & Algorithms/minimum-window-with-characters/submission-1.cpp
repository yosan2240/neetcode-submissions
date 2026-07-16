class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t;
        unordered_map<char, int> freq_window;
        int l = 0, r = 0;
        int count = 0;
        string result = "";

        if(s.size() < t.size())
            return "";

        /* Initialize the frequency table for t */
        for (char& ch : t) {
            freq_t[ch]++;
        }

        while(r < s.size()) {
            bool match = true;
            freq_window[s[r]]++;
            for (auto& [ch, count] : freq_t) {
                if (freq_window[ch] < count)
                    match = false;
            }
            cout << match << endl;
            while(match){
                if(result.empty() || r - l + 1 < result.size())
                    result = s.substr(l, r - l + 1);
                freq_window[s[l]]--;
                l++;
                match = true;
                for (auto& [ch, count] : freq_t) {
                    if (freq_window[ch] < count)
                    match = false;
                }
            }
            r++;
            cout << result << endl;
        }

        return result;
    }
};
