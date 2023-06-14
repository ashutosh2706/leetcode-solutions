class Solution {
private:
int last = 1e9, ans = 1e9;
void inorder(TreeNode* root) {
    if(root) {
        inorder(root->left);
        ans = min(ans, abs(last-root->val));
        last = root->val;
        inorder(root->right);
    }
}
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};