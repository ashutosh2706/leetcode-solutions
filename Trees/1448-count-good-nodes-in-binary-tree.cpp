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
    int count(TreeNode* root, int val) {
        if(root == nullptr) return 0;
        int cnt = count(root->left, max(val, root->val)) + count(root->right, max(val, root->val));
        return (root->val >= val) + cnt;
    }

    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
};