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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back(root->val);
        while(!q.empty()) {
            int sz = q.size(), n = -1e4;
            while(sz--) {
                TreeNode *t = q.front();
                q.pop();
                if(t->left) {
                    q.push(t->left);
                    n = t->left->val;
                }
                if(t->right) {
                    q.push(t->right);
                    n = t->right->val;
                }
            }
            if(n != -1e4) res.push_back(n);
        }
        return res;
    }
};