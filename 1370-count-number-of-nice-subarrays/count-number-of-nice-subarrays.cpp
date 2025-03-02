class Solution {

    int cnt(vector<int> &nums, int k) {
        if(k < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;

        while(r < nums.size()) {
            sum += (nums[r] % 2);

            while(sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans1 = cnt(nums, k);
        int ans2 = cnt(nums, k - 1);

        return (ans1 - ans2);
    }
};