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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MAX;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()) {
            int sz = q.size(); 
            while(sz--) {
                auto p = q.front(); q.pop();
                if(!p.first->left and !p.first->right) {
                    ans = min(ans, p.second);
                    continue;
                }
                if(p.first->left) {
                    q.push({p.first->left, p.second+1});
                }
                if(p.first->right) {
                    q.push({p.first->right, p.second+1});
                }
            }
        }
        return ans;
    }
};