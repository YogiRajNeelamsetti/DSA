class Solution {
public:
    int f(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int ind = i; ind <= j; ind++) {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(nums, i, ind - 1, dp) + f(nums, ind + 1, j, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return f(nums, 1, n, dp);
    }
};