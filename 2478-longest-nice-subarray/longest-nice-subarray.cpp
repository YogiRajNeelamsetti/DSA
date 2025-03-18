class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 1;
        int l = 0, r = 0;
        int n = nums.size();
        int orSum = 0;
        while(r < n) {
            if((orSum & nums[r]) == 0) {
                orSum |= nums[r];
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                orSum ^= nums[l];
                l++;
            }
        }

        return maxLen;
    }
};