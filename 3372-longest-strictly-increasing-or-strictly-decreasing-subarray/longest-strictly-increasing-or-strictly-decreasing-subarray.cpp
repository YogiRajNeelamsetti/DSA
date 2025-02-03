class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int iCount = 1, dCount = 1, maxLen = 1;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                dCount++;
                iCount = 1;
            }
            else if(nums[i] < nums[i + 1]) {
                iCount++;
                dCount = 1;
            } 
            else {
                iCount = 1;
                dCount = 1;
            }

            if(iCount > dCount) {
                if(iCount > maxLen) {
                    maxLen = iCount;
                }
            } else {
                if(dCount > maxLen) {
                    maxLen = dCount;
                }
            }

            //maxLen = max(maxLen, max(iCount, dCount));
        }
        
        
        return maxLen;
    }
};