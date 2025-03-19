class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] == 0) {
                cnt++;
                for(int j = i; j < i + 3; j++) {
                    nums[j] = nums[j] ^ 1;
                }
            } else {
                continue;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != 1) return -1;
        }

        return cnt;
    }
};