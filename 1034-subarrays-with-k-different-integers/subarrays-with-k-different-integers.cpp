class Solution {
    int cnt(vector<int> &nums, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while(r < nums.size()) {
            mpp[nums[r]]++;
            
            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = cnt(nums, k);
        int ans2 = cnt(nums, k - 1);
        return ans1 - ans2;
    }
};