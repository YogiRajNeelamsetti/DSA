class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<char, int> mpp;

        while(r < n) {
            if(mpp.find(s[r]) != mpp.end()) {
                if(mpp[s[r]] >= l) {
                    l = mpp[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            mpp[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};