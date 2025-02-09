class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<long long, long long> mpp;
        for(int i = 0; i < nums.size(); i++) {
            long long diff = i - nums[i];
            count += i - mpp[diff];
            mpp[diff]++;
        }

        return count;
    }
};