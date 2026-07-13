class Solution {
public:
    int characterReplacement(string s, int k) {
        // Always initialize arrays — uninitialized arrays contain garbage values in C++
        int frequency[26] = {};

        // Sliding window [l, r] representing the current candidate substring
        int l = 0, r = 0;
        // maxfreq: frequency of the most common character in the current window
        int maxfreq = 0;
        int result = 0;

        while (r < s.size()) {
            // Expand window to the right and update frequency + maxfreq
            frequency[s[r] - 'A']++;
            maxfreq = max(maxfreq, frequency[s[r] - 'A']);

            // Window is invalid when non-dominant characters exceed k replacements.
            // Since r moves one step at a time, window can only become invalid by 1 unit,
            // so a single l++ always restores validity — if is equivalent to while here.
            if (r - l + 1 - maxfreq > k) {
                frequency[s[l] - 'A']--;
                l++;
            }

            // Window is always valid here — update result
            result = max(result, r - l + 1);
            r++;
        }

        return result;
    }
};