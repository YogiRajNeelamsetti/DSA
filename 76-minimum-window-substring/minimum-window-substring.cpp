class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = 1e9, cnt = 0, sIdx = -1, l = 0, r = 0;
        unordered_map<char, int> mpp;

        for(char &c : t) mpp[c]++;
        
        while(r < s.size()) {
            if(mpp[s[r]] > 0) cnt += 1;
            mpp[s[r]]--;

            while(cnt == t.size()) {
                if((r - l + 1) < minLen) {
                    minLen = (r - l + 1);
                    sIdx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};