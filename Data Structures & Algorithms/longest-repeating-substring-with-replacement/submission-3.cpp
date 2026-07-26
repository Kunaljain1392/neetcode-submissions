class Solution {
public:
    int characterReplacement(string s, int k) {

        // hr char ki freq track krenge 
        // jb window ka size - max freq > ayye k se mtlb k se jyada
        // replacement krne padenge
        int l=0;
        int ans = 0;
        int maxFreq = 0;
        unordered_map<char,int> mp;
        
        for(int r=0;r<s.length();r++) {
            mp[s[r]] += 1;
            int windowSize = r-l+1;
            maxFreq = max(maxFreq,mp[s[r]]);
            while(((r-l+1)-maxFreq) > k) {
                mp[s[l]]--;
                l++;
                windowSize--;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
