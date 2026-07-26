class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        bool ans = false;

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26,0);
        int k = s1.length();
        // s1 freq
        for(int i=0;i<k;i++) {
            s1Freq[s1[i] - 'a']++;
        }

        // k size window
        for(int i=0;i<k;i++) {
            s2Freq[s2[i] - 'a']++;
        }
        if(s1Freq == s2Freq) {
            ans = true;
        }
        for(int i=k;i<s2.length();i++) {
            s2Freq[s2[i-k] - 'a']--;
            s2Freq[s2[i] - 'a']++;
            if(s1Freq == s2Freq) {
                ans = true;
            }
        }
        return ans;

    }
};
