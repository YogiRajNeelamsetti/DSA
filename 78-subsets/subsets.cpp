class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        int n = nums.size();

        for(int i = 0; i <= (1 << n) - 1; i++) {
            vector<int> set;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) set.push_back(nums[j]);
            }
            powerSet.push_back(set);
        }
        return powerSet;
    }
};