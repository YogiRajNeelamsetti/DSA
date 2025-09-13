class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();

        if(n != m) return false;
        vector<int> cntA(26, 0);
        vector<int> cntB(26, 0);

        for(int i = 0; i < n; i++) {
            cntA[s[i] - 'a']++;
            cntB[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(cntA[i] != cntB[i]) return false;
        }

        return true;
    }
};