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
private:
int getmax(int a, int b, int c, int d) {
    int x = max(a,b);
    int y = max(c,d);
    return max(x,y);
}

int find(TreeNode* root, int& ans) {
    if(root==NULL) return 0;
    int left = find(root->left, ans);
    int right = find(root->right, ans);
    int value = root->val;
    ans = max(ans, getmax(value+left, value+right, value, value+left+right));
    return getmax(value+left, value+right, value, 0);
}
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        find(root,ans);
        return ans;
    }
};