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
    vector<vector<int>> res;
    void solve(TreeNode* root, int t, vector<int> &v) {
        if(root) {
            v.push_back(root->val);
            if(t-(root->val) == 0 and (!root->left and !root->right) and !v.empty()) {
                res.push_back(v);
            } else {
                solve(root->left, t-(root->val), v);
                solve(root->right, t-(root->val), v);
            }
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        solve(root, targetSum, v);
        return res;
    }
};