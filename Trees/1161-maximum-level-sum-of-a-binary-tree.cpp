class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        pair<int, int> res = make_pair(root->val, 1);
        while(!q.empty()) {
            int sz = q.size();
            int ans = 0;
            while(sz--) {
                TreeNode *tmp = q.front();
                q.pop();
                ans += tmp->val;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            if(ans > res.first) {
                res.first = ans;
                res.second = level;
            }
            level++;
        }
        return res.second;
    }
};