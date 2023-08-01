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
    int widthOfBinaryTree(TreeNode* root) {
        typedef long long int ll;
        queue<pair<TreeNode*, ll>> q;
        q.push({root,0});
        ll width = 0;
        while(!q.empty()) {
            int sz = q.size();
            if(sz) width = max(width, q.back().second-q.front().second+1);
            ll mini = INT_MAX;
            while(sz--) {
                TreeNode* t = q.front().first;
                ll idx = q.front().second;
                q.pop();
                mini = min(mini, idx);
                ll ind = idx - mini;
                if(t->left) q.push({t->left, 2*ind+1});
                if(t->right) q.push({t->right, 2*ind+2});
            }
        }
        return width;
    }
};