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
    long curr = 0;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->right);
            root -> val += curr;
            curr = root->val;
            inorder(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
};