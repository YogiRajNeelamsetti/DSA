class Solution {
public:

    int countWays(vector<int> &nums, int n, int target) {
        vector<vector<int>> dp(n, vector<int>(target + 1));

        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1;

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                int notTake = 0 + dp[i - 1][t];
                int take = 0;

                if(nums[i] <= t) take = dp[i - 1][t - nums[i]];

                dp[i][t] = take + notTake;

            }
        }

        return dp[n - 1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int total = 0;

        for(int &ele : nums) {
            total += ele;
        }

        if((total - target) < 0 || (total - target) % 2) return 0;

        return countWays(nums, n, (total - target) / 2);
    
    }
};