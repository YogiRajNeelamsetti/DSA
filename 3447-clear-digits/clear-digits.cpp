class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int i = 0;
        while(i < s.size()) {
            if(isdigit(s[i])) {
                s.erase(i, 1);
                i--;
                s.erase(i, 1);
            } else {
                i++;
            }
            
        }
        

        return s;
    }
};