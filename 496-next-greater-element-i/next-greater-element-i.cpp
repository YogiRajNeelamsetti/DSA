class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> mpp1;

        for(int i = 0; i < n; i++) {
            mpp1[nums1[i]] = i;
        }

        stack<int> st;
        vector<int> ans(n);

        for(int i = m - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(mpp1.find(nums2[i]) != mpp1.end()) {
                if(st.empty()) {
                    ans[mpp1[nums2[i]]] = -1;
                } else {
                    ans[mpp1[nums2[i]]] = st.top();
                }
            }
            st.push(nums2[i]);
        }

        return ans;
    }
};