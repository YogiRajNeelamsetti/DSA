class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n; i += 2) {
            if(nums[i] == nums[i - 1]) cnt++;
            else return false;
        }

        return cnt == (n / 2);
    }
};