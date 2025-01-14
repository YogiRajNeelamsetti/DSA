class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, maximum = LONG_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum > maximum) {
                maximum = sum;
            }

            if(sum < 0) sum = 0;
        }

        return maximum;
    }
};