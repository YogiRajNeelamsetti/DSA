class disJointSet {
    

    public:
        vector<int> size, parent;

        disJointSet(int n) {
            size.resize(n, 1);
            parent.resize(n);

            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findParent(int node) {
            if(node == parent[node]) return node;

            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int uParentU = findParent(u);
            int uParentV = findParent(v);

            if(uParentU == uParentV) return;

            if(size[uParentU] < size[uParentV]) {
                parent[uParentU] = uParentV;
                size[uParentV] += size[uParentU];
            } else {
                parent[uParentV] = uParentU;
                size[uParentU] += size[uParentV];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0;
        int components = 0;

        disJointSet ds(n);
        for(auto it : connections) {
            if(ds.findParent(it[0]) == ds.findParent(it[1])) {
                extraEdges++;
            } else {
                ds.unionBySize(it[0], it[1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) components++;
        }

        return components - 1 <= extraEdges ? components - 1 : -1;
    }
};