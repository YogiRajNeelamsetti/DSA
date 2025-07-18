class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> findnse(int n, vector<int> &arr) {
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findpse(int n, vector<int> &arr) {
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        vector<int> pse = findpse(n, arr);
        vector<int> nse = findnse(n, arr);

        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + (1LL * left * right * arr[i]) % MOD) % MOD;
        }

        return total;
    }
};