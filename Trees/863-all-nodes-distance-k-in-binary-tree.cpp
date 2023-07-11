/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> map;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto n = q.front(); q.pop();
                if(n->left) {
                    q.push(n->left);
                    map[n->val].push_back(n->left->val);
                    map[n->left->val].push_back(n->val);
                }
                if(n->right) {
                    q.push(n->right);
                    map[n->val].push_back(n->right->val);
                    map[n->right->val].push_back(n->val);
                }
            }
        }
        vector<int> res;
        int vis[501] = {0};
        vis[target->val] = 1;
        queue<pair<int,int>> pq;
        pq.push({target->val,0});
        while(!pq.empty()) {
            int sz = pq.size();
            while(sz--) {
                auto p = pq.front(); pq.pop();
                if(p.second == k) {
                    res.push_back(p.first);
                    continue;
                }
                for(auto &adj : map[p.first]) {
                    if(!vis[adj]) {
                        pq.push({adj, p.second+1});
                        vis[adj] = 1;
                    }
                }
            }
        }
        return res;
    }
};