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
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> nodes {root->val};
        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while(sz--) {
                TreeNode *t = q.front(); q.pop();
                if(t->left) {
                    q.push(t->left);
                    temp.push_back(t->left->val);
                }
                if(t->right) {
                    q.push(t->right);
                    temp.push_back(t->right->val);
                }
            }

            if(!temp.empty()) nodes = temp;

        }
        return accumulate(begin(nodes), end(nodes), 0);
    }
};