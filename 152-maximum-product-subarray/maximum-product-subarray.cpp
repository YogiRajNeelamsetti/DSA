class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n - 1 - i];

            if(pre > suff) {
                if(pre > ans) {
                    ans = pre;
                }
            } else {
                if(suff > ans) {
                    ans = suff;
                }
            }
        }

        return ans;
    }
};