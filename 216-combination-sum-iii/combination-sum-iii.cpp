class Solution {
public:
    void combination(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target, int k) {
        if(target == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if(ds.size() > k) return;

        for(int i = ind; i < arr.size(); i++) {
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            combination(i + 1, arr, ans, ds, target - arr[i], k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        for(int i = 0; i < 9; i++) {
            arr[i] = i + 1;
        }
        vector<vector<int>> ans;
        vector<int> ds;

        combination(0, arr, ans, ds, n, k);

        return ans;
    }
};