class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* Store the duplicated character's position, such that we can 
        restart from one step after it */
        unordered_map<char, int> seen;
        /* We use sliding window to calculate the longest substring */
        int l = 0, r = 0;
        int result = 0;

        if (!s.size())
            return 0;

        while (r < s.size()) {
            if (seen.count(s[r])){
                result = max(result, r - l); 
                l = max(l, seen[s[r]] + 1);
            }
            seen[s[r]] = r;
            r++;
        }
        result = max(result, r - l);

        return result;
    }
};
