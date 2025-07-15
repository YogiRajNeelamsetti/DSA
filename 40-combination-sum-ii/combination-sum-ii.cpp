class Solution {
public:

    void combination(int i, int target, vector<int> &candidates, set<vector<int>> &ans, vector<int> &arr) {
        if(target == 0) {
            ans.insert(arr);
        }

        for(int ind = i; ind < candidates.size(); ind++) {
            if(ind > i && candidates[ind] == candidates[ind - 1]) continue;
            if(candidates[ind] > target) break;
            arr.push_back(candidates[ind]);
            combination(ind + 1, target - candidates[ind], candidates, ans, arr);
            arr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        combination(0, target, candidates, ans, arr);

        vector<vector<int>> res;

        for(auto it : ans) {
            res.push_back(it);
        }
        return res;
    }
};