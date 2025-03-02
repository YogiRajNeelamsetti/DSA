class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxLen = 0, zeroes = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) zeroes++;
            if(zeroes > k) {
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= k) {
                if((r - l + 1) > maxLen) {
                    maxLen = (r - l + 1);
                }
            }
            r++;
        }

        return maxLen;
    }
};