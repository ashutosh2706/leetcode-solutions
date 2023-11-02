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
    int cnt = 0;
    pair<int,int> f(TreeNode* root) {
        if(root == nullptr) return make_pair(0,0);
        auto l = f(root->left);
        auto r = f(root->right);
        int p1 = l.first + r.first + (root->val); // sum
        int p2 = l.second + r.second + 1; // count
        double av = p1/p2;
        cout << root->val << " " << p1 << " " << p2 << endl;
        if(root->val == round(av)) cnt++;
        return pair<int,int>{p1,p2};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return cnt;
    }
};