class Node{
    public:
        Node* links[2];

        bool containKey(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
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
                    node -> put(bit, new Node());
                }
                node = node -> get(bit);
            }
        }

        int getMax(int num) {
            int maxNum = 0;
            Node* node = root;

            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(node -> containKey(1 - bit)) {
                    maxNum |= (1 << i);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n = nums.size();

        for(int &ele : nums) {
            trie.insert(ele);
        }

        int maxi = 0;

        for(int &ele : nums) {
            maxi = max(maxi, trie.getMax(ele));
        }

        return maxi;
    }
};