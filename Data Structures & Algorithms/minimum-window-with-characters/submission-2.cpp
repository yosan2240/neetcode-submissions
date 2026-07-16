class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t;      // required character frequencies from t
        unordered_map<char, int> freq_window; // character frequencies in current window
        int l = 0, r = 0;
        string result = "";

        // edge case: t can't fit in s
        if (s.size() < t.size())
            return "";

        // build frequency table for t
        for (char& ch : t)
            freq_t[ch]++;

        while (r < s.size()) {
            // expand window to the right
            freq_window[s[r]]++;

            // check if current window satisfies all characters in t
            bool match = true;
            for (auto& [ch, count] : freq_t)
                if (freq_window[ch] < count)
                    match = false;

            // shrink window from the left as long as it's still valid
            while (match) {
                // update result if this window is smaller
                if (result.empty() || r - l + 1 < result.size())
                    result = s.substr(l, r - l + 1);

                // remove leftmost character and shrink window
                freq_window[s[l]]--;
                l++;

                // recheck validity after shrinking
                match = true;
                for (auto& [ch, count] : freq_t)
                    if (freq_window[ch] < count)
                        match = false;
            }
            r++;
        }

        return result;
    }
};