class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> res;
        while(ss >> word) {
            res.push_back(word);
        }

        s = "";
        for(int i = res.size() - 1; i >= 0; i--) {
            s += res[i];
            if(i != 0) s += " ";
        }
        return s;
    }
};