class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack == needle) return 0;

        int n = haystack.size();
        int m = needle.size();
        
        int start = -1;

        int l = 0, r = 0;
        while(l < n) {
            if(haystack[l] == needle[0]) {
                if(l <= n - m && haystack.substr(l, m) == needle) return l;
            }
            l++;
        }

        return -1;
    }
};