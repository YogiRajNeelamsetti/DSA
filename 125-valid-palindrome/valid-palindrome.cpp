#include <string.h>
class Solution {
    
public:
    bool isPalindrome(string s) {
        string str = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                str += tolower(s[i]);
            }
        }

        n = str.size();

        for(int i = 0; i < n / 2; i++) {
            if(str[i] != str[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};