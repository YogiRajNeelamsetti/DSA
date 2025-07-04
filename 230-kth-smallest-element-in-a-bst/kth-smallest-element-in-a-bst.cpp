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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int cnt = 0;
        int ans = -1; 

        while(root) {
            if(root -> left == NULL) {
                cnt++;
                if(cnt == k) {
                    ans = root -> val;
                }
                root = root -> right;
            } else {
                TreeNode* prev = root -> left;
                while(prev -> right && prev -> right != root)
                    prev = prev -> right;
                if(prev -> right == NULL) {
                    prev -> right = root;
                    root = root -> left;
                } else {
                    cnt++;
                    if(cnt == k) {
                        ans = root -> val;
                    }
                    prev -> right = NULL;
                    root = root -> right;
                }
            }
        }
        return ans;
    }
};