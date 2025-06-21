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
    TreeNode* findLastRight(TreeNode* root) {
        if(root -> right == NULL) return root;

        return findLastRight(root -> right);
    }
    TreeNode* deleteHelp(TreeNode* root) {
        if(root -> left == NULL) return root -> right;
        else if(root -> right == NULL) return root -> left;

        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRight(root -> left);

        lastRight -> right = rightChild;

        return root -> left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) {
            return deleteHelp(root);
        }

        TreeNode* node = root;
        while(node) {
            if(node -> val > key) {
                if(node -> left && node -> left -> val == key) {
                    node -> left = deleteHelp(node -> left);
                    break;
                } else {
                    node = node -> left;
                }
            } else {
                if(node -> right && node -> right -> val == key) {
                    node -> right = deleteHelp(node -> right);
                    break;
                } else {
                    node = node -> right;
                }
            }
        }
        return root;
    }
};