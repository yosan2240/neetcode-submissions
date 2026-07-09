class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= '0' && c <= '9') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z');
    }

    bool isPalindrome(string s) {
        string new_s = "";

        // I decide to keep the original string for building good habbit
        for (char& c : s) {
            // We only keep the alphanumeric characters
            if (isAlphanumeric(c)) {
                char lower = tolower(c);
                new_s.push_back(lower);
            }
        } 

        int left = 0;
        int right = new_s.size() - 1;


        while (left < right) {
            if (new_s[left] != new_s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
