class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> mpp;
        long long sum = 0;
        int n = nums.size();
        mpp[sum] = 1;
        int subArrayCount = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int remove = sum - k;
            subArrayCount += mpp[remove];
            mpp[sum]++;
        }
        

        return subArrayCount;
    }
};