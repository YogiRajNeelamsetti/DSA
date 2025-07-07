class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<long long> dp(n, 1), hash(n, 0);

        int lastIdx = 0, maxi = 1;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if((nums[i] % nums[j] == 0) && (1 + dp[j] > dp[i])) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);

        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        reverse(temp.begin(), temp.end());

        return temp;
    }
};