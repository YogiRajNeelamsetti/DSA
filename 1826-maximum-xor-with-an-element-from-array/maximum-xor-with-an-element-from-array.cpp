class Node {
    Node* links[2];

    public:
        bool containKey(int bit) {
            return links[bit] != NULL;
        }

        void put(int bit) {
            links[bit] = new Node();
        }

        Node* get(int bit) {
            return links[bit];
        }
};

class Trie {
    Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;
            
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(!node -> containKey(bit)) {
                    node -> put(bit);
                }
                node = node -> get(bit);
            }
        }

        int getMax(int num) {
            Node* node = root;
            int maxNum = 0;

            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(node -> containKey(1 - bit)) {
                    maxNum = maxNum | (1 << i);
                    node = node -> get(1 - bit);
                } else {
                    node = node -> get(bit);
                }
            }

            return maxNum;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> oQ;

        for(int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, 0);
        int idx = 0;
        Trie trie;

        for(int i = 0; i < q; i++) {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qIdx = oQ[i].second.second;

            while(idx < n && nums[idx] <= ai) {
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[qIdx] = -1;
            else ans[qIdx] = trie.getMax(xi);
        }
        return ans;
    }
};