class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++) {
            int p1 = i + 1, p2 = n - 1;
            while(p1 < p2) {
                int sum = nums[p1] + nums[p2];
                sum += nums[i];
                if(abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                if(sum < target) {
                    p1++;
                } else if(sum > target) {
                    p2--;
                } else { 
                    return sum;
                }
            }
        }

        return closest;
    }
};