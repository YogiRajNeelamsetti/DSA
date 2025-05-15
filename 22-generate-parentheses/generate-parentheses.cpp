class Solution {
public:
    void parentheses(vector<string> &ans, int open, int close, string curr, int n) {
        if(close == n) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            parentheses(ans, open + 1, close, curr + "(", n);
        }
        if(close < open) {
            parentheses(ans, open, close + 1, curr + ")", n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        parentheses(ans, 0, 0, "", n);

        return ans;
    }
};