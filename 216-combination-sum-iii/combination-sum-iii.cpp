class Solution {
public:
    void combination(int ind, vector<vector<int>> &ans, vector<int> &ds, int target, int k) {
        if(ds.size() == k) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if(ds.size() > k) return;

        for(int i = ind; i <= 9; i++) {
            if(i > target) break;
            ds.push_back(i);
            combination(i + 1, ans, ds, target - i, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        combination(1, ans, ds, n, k);

        return ans;
    }
};