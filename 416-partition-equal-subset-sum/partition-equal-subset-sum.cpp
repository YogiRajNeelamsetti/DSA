class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int &ele : nums) sum += ele;

        if(sum % 2) return false;

        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if(nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if(nums[i] <= target) take = dp[i - 1][target - nums[i]];

                dp[i][target] = take | notTake;
            }
        }

        return dp[n - 1][sum];
    }
};