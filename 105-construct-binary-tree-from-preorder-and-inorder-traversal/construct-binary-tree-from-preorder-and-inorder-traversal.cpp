/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* buildTree(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);

        int inRoot = inMap[pre[preStart]];
        int numsLeft = inRoot - inStart;

        root -> left = buildTree(pre, preStart + 1, numsLeft + preStart, in, inStart, inRoot - 1, inMap);
        root -> right = buildTree(pre, numsLeft + preStart + 1, preEnd, in, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        int n = inorder.size();

        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);

        return root;
    }
};