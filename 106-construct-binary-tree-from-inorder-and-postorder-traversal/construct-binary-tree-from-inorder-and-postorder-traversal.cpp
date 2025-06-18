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

    TreeNode* buildTreeHelp(vector<int> &post, int postStart, int postEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(post[postEnd]);

        int inRoot = inMap[post[postEnd]];
        int numsLeft = inRoot - inStart;

        root -> left = buildTreeHelp(post, postStart, postStart + numsLeft - 1, in, inStart, inRoot - 1, inMap);
        root -> right = buildTreeHelp(post, postStart + numsLeft, postEnd - 1, in, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> inMap;

        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTreeHelp(postorder, 0, n - 1, inorder, 0, n - 1, inMap);
        
        return root;
    }
};