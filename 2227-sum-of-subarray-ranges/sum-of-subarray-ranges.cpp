class Solution {
public:
    long long MOD = 1e9 + 7;

    vector<int> findpge(int n, vector<int> &arr) {
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pge;
    }

    vector<int> findnge(int n, vector<int> &arr) {
        vector<int> nge(n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nge;
    }

    long long sumSubarrayMax(int n, vector<int> &arr) {
        vector<int> pge = findpge(n, arr);
        vector<int> nge = findnge(n, arr);

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;

            sum = (sum + (1LL * left * right * arr[i]));
        }


        return sum;
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

    long long sumSubarrayMins(int n, vector<int> &arr) {
        
        vector<int> nse = findnse(n, arr);
        vector<int> pse = findpse(n, arr);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            
            sum = (sum + (1LL * left * right * arr[i]));

        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return (sumSubarrayMax(n, nums) - sumSubarrayMins(n, nums));
    }
};