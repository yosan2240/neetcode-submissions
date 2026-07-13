class Solution {
public:
    int characterReplacement(string s, int k) {
        int frequency[26] = {};
        int l = 0, r = 0;
        int maxfreq = 0, replaced = 0;
        int result = 0;
        while(r < s.size()) {
            frequency[s[r] - 'A']++;
            maxfreq = max(maxfreq, frequency[s[r] - 'A']);
            replaced = r - l + 1 - maxfreq;
            
            if (replaced > k) {
                frequency[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }

        return result;
    }
};
