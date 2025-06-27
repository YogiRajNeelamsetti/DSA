class Solution {
public:
    bool dfs(int crs, vector<vector<int>>& prerequisites, set<int> &visited, set<int> &cycle, map<int, vector<int>> &mpp, vector<int> &output) {
        if(cycle.count(crs)) return false;
        if(visited.count(crs)) return true;

        cycle.insert(crs);

        for(int pre : mpp[crs]) {
            if(dfs(pre, prerequisites, visited, cycle, mpp, output) == false) return false;
        }
        cycle.erase(crs);
        visited.insert(crs);
        output.push_back(crs);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mpp;
        for(vector<int> course : prerequisites) {
            mpp[course[0]].push_back(course[1]);
        }
        set<int> visited, cycle;
        vector<int> output;

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, prerequisites, visited, cycle, mpp, output)) return {};
        }
        return output;
    }
};