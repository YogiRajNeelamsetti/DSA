class Solution {
public:
    // bool checkBipartite(int start, int n, vector<vector<int>>& graph, vector<int> &color) {
    //     queue<int> q;
    //     q.push(start);

    //     color[start] = 0;

    //     while(!q.empty()) {
    //         int node = q.front();
    //         q.pop();

    //         for(int adjNode : graph[node]) {
    //             if(color[adjNode] == -1) {
    //                 color[adjNode] = !color[node];
    //                 q.push(adjNode);
    //             } else if(color[adjNode] == color[node]) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool dfs(int node, int clr, vector<vector<int>>& graph, vector<int> &color) {
        color[node] = clr;

        for(int adjNode : graph[node]) {
            if(color[adjNode] == -1) {
                if(!dfs(adjNode, !clr, graph, color)) return false;
            }
            else if(color[adjNode] == clr) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(dfs(i, 0, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};