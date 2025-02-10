class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        long long sum = 0;
        int n = nums.size();
        mpp[sum] = 1;
        int subArrayCount = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mpp.count(sum - k)) {
                subArrayCount += mpp[sum - k];
            }
            mpp[sum]++;
        }
        

        return subArrayCount;
    }
};