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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 and !root2) return 1;
        if(!root1 or !root2) return 0;
        bool b = root1->val == root2->val;
        if(root1->left and root2->left) {
            if(root1->left->val == root2->left->val) {
                b =b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
            } else {
                swap(root2->left, root2->right);
                b =b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
            }
        } else if((!root1->left and root2->left) or (root1->left and !root2->left)) {
            swap(root2->left, root2->right);
            b = b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
        } else if(root1->right and root2->right) {
            if(root1->right->val == root2->right->val) 
                b =b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
            else {
                swap(root2->left, root2->right);
                b =b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
            } 
        } else if((!root1->left and root2->left) or (root1->left and !root2->left)) {
            swap(root2->left, root2->right);
            b = b and flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
        }
        return b;

    }
};