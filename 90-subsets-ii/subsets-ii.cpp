class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++) {
            vector<int> arr;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    arr.push_back(nums[j]);
                }
                sort(arr.begin(), arr.end());
                s.insert(arr);
            }
        }
        vector<vector<int>> ans;
        for(auto it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};