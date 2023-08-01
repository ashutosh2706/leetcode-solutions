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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool b = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode *t = q.front();
                q.pop();
                if(t and b) return 0;
                if(t == NULL) {
                    b = 1;
                    continue;
                }
                t->left ? q.push(t->left) : q.push(NULL);
                t->right ? q.push(t->right) : q.push(NULL);
            }
        }
        return 1;
    }
};