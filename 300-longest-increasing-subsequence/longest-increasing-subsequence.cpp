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
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){
                
                int notTake = 0 + dp[ind+1][prev_index +1];
        
                int take = 0;
        
                if(prev_index == -1 || nums[ind] > nums[prev_index]){
                    
                    take = 1 + dp[ind+1][ind+1];
                }
        
                dp[ind][prev_index+1] = max(notTake,take);
                
            }
        }

        return dp[0][0];
    }
};