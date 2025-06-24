class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) take += prev2;
            int nonTake = prev;

            int curr = max(take, nonTake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> nums1, nums2;

        for(int i = 0; i < n; i++) {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != n - 1) nums2.push_back(nums[i]);
        }

        return max(helper(nums1), helper(nums2));
    }
};