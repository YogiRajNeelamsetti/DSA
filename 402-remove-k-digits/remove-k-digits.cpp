class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        int n = num.size();

        stack<char> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        while(res.size() > 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};