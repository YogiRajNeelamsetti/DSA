class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mpp;
        mpp['{'] = '}';
        mpp['('] = ')';
        mpp['['] = ']';
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(st.empty()) return false;
                char top = st.top();
                if(mpp[top] == s[i]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};