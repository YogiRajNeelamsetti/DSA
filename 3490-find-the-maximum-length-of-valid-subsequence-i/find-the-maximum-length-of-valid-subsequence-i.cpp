class Solution {
public:
    vector<vector<int>> pattern = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int res = 0;

        for(auto &it : pattern) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] % 2 == it[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }

        return res;
    }
};