class Solution {
public:
    bool dfs(int crs, vector<vector<int>>& prerequisites, map<int, vector<int>> &mpp, set<int> &visited) {
        if(visited.find(crs) != visited.end()) 
            return false;
        if(mpp[crs].empty())
            return true;
        
        visited.insert(crs);

        for(int pre : mpp[crs]) {
            if(!dfs(pre, prerequisites, mpp, visited)) return false;
        }

        visited.erase(crs);
        mpp[crs] = {};

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mpp;
        for(vector<int> course : prerequisites) {
            mpp[course[0]].push_back(course[1]);
        }
        set<int> visited;
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, prerequisites, mpp, visited)) return false;
        }
        return true;
    }

};