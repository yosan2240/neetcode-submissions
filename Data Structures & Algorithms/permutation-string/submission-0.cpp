class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int freq_s1[26] = {};
        int freq_window[26] = {};
        int l = 0, r = s1.size() - 1;
        int counter = 0;
        for(char ch : s1) 
            freq_s1[ch - 'a']++;

        int i = 0;
        while(i <= r){
            freq_window[s2[i] - 'a']++;
            i++;     
        }
        for(int i = 0; i < 26; i++)
            if(freq_window[i] == freq_s1[i])
                counter++;
        if(counter == 26)
            return true;

        while(r < (int)s2.size() - 1) {
            int left_char = s2[l] - 'a';
            if(freq_window[left_char] == freq_s1[left_char])
                counter--;
            freq_window[left_char]--;
            if(freq_window[left_char] == freq_s1[left_char])
                counter++;
            
            l++;
            r++;
            
            int right_char = s2[r] - 'a';
            if(freq_window[right_char] == freq_s1[right_char])
                counter--;
            freq_window[right_char]++;
            if(freq_window[right_char] == freq_s1[right_char])
                counter++;

            if(counter == 26)
                return true;
        }

        return false;
    }
};
