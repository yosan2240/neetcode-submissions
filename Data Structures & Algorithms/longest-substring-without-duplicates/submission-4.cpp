class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* Store each character's most recent index, so we can
           jump the left boundary past any duplicate instantly */
        unordered_map<char, int> seen;

        /* Sliding window [l, r] representing the current valid substring */
        int l = 0, r = 0;
        int result = 0;

        if (!s.size())
            return 0;

        while (r < s.size()) {
            if (seen.count(s[r]))
                /* Duplicate found — shrink window from the left.
                   Use max() to ensure l never moves backwards
                   (previous occurrence may already be outside the window) */
                l = max(l, seen[s[r]] + 1);

            /* Always update to the latest index of this character */
            seen[s[r]] = r;

            /* Window size is r - l + 1; update result if it's the largest seen */
            result = max(result, r - l + 1);
            r++;
        }

        return result;
    }
};