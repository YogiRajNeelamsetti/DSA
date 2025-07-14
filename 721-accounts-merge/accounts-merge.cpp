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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        disJointSet ds(n);
        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mpp.find(mail) == mpp.end()) {

                    mpp[mail] = i;
                } else {
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it : mpp) {
            string mail = it.first;
            int node = ds.findParent(it.second);

            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(merged[i].size() == 0) continue;

            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(string s : merged[i]) {
                temp.push_back(s);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};