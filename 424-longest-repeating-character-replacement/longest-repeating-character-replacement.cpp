class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> mpp;

        while(r < s.size()) {
            mpp[s[r]]++;

            maxFreq = max(maxFreq, mpp[s[r]]);

            if((r - l + 1) - maxFreq > k) {
                mpp[s[l]]--;
                maxFreq = 0;
                l++;
            }

            if((r - l + 1) - maxFreq <= k) {
                maxLen = max(maxLen, (r - l + 1));
            }
            r++;
        }

        return maxLen;
    }
};