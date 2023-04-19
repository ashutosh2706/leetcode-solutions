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
int ans = 0;
void dfs(TreeNode *root, int steps, bool left) {
    if(root == nullptr) {
        ans = max(ans, steps - 1);
        return;
    } 

    if(left) {
        dfs(root->left, steps + 1, 0);
        dfs(root->right, 1, 1);
    } else {
        dfs(root->right, steps + 1, 1);
        dfs(root->left, 1, 0);
    }
}
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 1);
        return ans;
    }
};