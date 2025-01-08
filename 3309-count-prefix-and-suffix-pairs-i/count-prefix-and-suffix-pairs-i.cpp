class Solution {

    bool isPrefixAndSuffix(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        if(n > m) return false;
        
        for(int i = 0; i < n; i++) {
            if(str1[i] != str2[i]) return false;
        } 

        for(int i = 0; i < n; i++) {
            if(str1[n - 1 - i] != str2[m - 1 - i]) return false;
        } 

        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }

        return count;
    }
};