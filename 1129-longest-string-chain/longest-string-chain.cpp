class Solution {
public:
    bool compare(string &s1, string &s2) {
        if(s1.size() != 1 + s2.size()) return false;
        int first = 0, second = 0;

        while(first < s1.size()) {
            if(second < s2.size() && s1[first] == s2[second]) {
                first++, second++;
            } else {
                first++;
            }
        }

        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<long long> dp(n, 1);

        int  maxi = 1;
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(compare(words[i], words[j]) && (1 + dp[j] > dp[i])) {
                    dp[i] = 1 + dp[j];
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};