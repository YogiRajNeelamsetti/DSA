class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> res;

        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i = 0; i < n; i++) {
            for(char &ch : strs[i]) {
                freq[i][ch - 'a']++;
            }
        }

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            vector<string> str;

            if(!vis[i]) str.push_back(strs[i]);
            vis[i] = 1;
            for(int j = i + 1; j < n; j++) {
                bool flag = true;
                for(int k = 0; k < 26; k++) {
                    if(freq[i][k] != freq[j][k]) {
                        flag = false;
                        break;
                    }
                }

                if(flag && !vis[j]) {
                    vis[j] = 1;
                    str.push_back(strs[j]);
                }
            }

            if(!str.empty()) res.push_back(str);
        }

        return res;
    }
};