class Solution {
public:
    int f(vector<int> &nums, int n, vector<vector<int>> &dp, int ind, int prevIdx) {
        if(ind == n)
            return 0;
        
        if(dp[ind][prevIdx + 1] != -1) return dp[ind][prevIdx + 1];

        int len = 0 + f(nums, n, dp, ind + 1, prevIdx);
        if(prevIdx == -1 || nums[ind] > nums[prevIdx]) {
            len = max(len, 1 + f(nums, n, dp, ind + 1, ind));
        }

        return dp[ind][prevIdx + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return f(nums, n, dp, 0, -1);
    }
};