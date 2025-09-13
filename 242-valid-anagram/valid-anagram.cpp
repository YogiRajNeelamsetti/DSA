class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();

        if(n != m) return false;
        vector<int> cnt(26, 0);

        for(int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }

        for(int i = 0; i < m; i++) {
            cnt[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0) return false;
        }

        return true;
    }
};