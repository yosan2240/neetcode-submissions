class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // A permutation of s1 can't fit in s2 if s1 is longer
        if (s1.size() > s2.size()) return false;

        int freq_s1[26] = {};     // character frequencies of s1
        int freq_window[26] = {}; // character frequencies of current window in s2
        int l = 0, r = s1.size() - 1;

        // counter tracks how many of the 26 characters have matching frequencies
        // between freq_s1 and freq_window. counter == 26 means the window is a permutation.
        int counter = 0;

        // Build frequency table for s1
        for (char ch : s1)
            freq_s1[ch - 'a']++;

        // Initialize the first window of size s1.size()
        int i = 0;
        while (i <= r) {
            freq_window[s2[i] - 'a']++;
            i++;
        }

        // Count how many characters already match between the first window and s1
        for (int i = 0; i < 26; i++)
            if (freq_window[i] == freq_s1[i])
                counter++;
        if (counter == 26)
            return true;

        // Slide the fixed-size window across s2
        while (r < (int)s2.size() - 1) {
            // Remove left character from window.
            // Update counter before and after the frequency change,
            // since removing a character can break or create a match.
            int left_char = s2[l] - 'a';
            if (freq_window[left_char] == freq_s1[left_char]) counter--;
            freq_window[left_char]--;
            if (freq_window[left_char] == freq_s1[left_char]) counter++;

            l++;
            r++;

            // Add right character to window.
            // Same logic: check counter before and after the frequency change.
            int right_char = s2[r] - 'a';
            if (freq_window[right_char] == freq_s1[right_char]) counter--;
            freq_window[right_char]++;
            if (freq_window[right_char] == freq_s1[right_char]) counter++;

            if (counter == 26)
                return true;
        }

        return false;
    }
};