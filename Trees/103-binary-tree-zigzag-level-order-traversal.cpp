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
 #define ss second
 #define ff first
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    TreeNode* tmp;
    int sz,lev;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()) {
        sz=q.size();
        lev=q.front().ss;
        vector<int> level(sz,0);
        for(int i=0; i<sz; i++) {
            tmp = q.front().ff;
            q.pop();
            int ind = lev%2==0 ? i : sz-1-i;
            level[ind]=tmp->val;
            if(tmp->left) q.push({tmp->left,lev+1});
            if(tmp->right) q.push({tmp->right,lev+1});
        }
        ans.push_back(level);
    }
    return ans;
    }
};