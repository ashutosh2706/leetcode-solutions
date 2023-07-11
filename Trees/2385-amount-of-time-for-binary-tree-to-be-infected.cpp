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
    void construct(TreeNode* root, unordered_map<int, vector<int>>& map) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto p = q.front(); q.pop();
                if(p->left) {
                    map[p->val].push_back(p->left->val);
                    map[p->left->val].push_back(p->val);
                    q.push(p->left);
                }
                if(p->right) {
                    map[p->val].push_back(p->right->val);
                    map[p->right->val].push_back(p->val);
                    q.push(p->right);
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> map;
        construct(root, map);
        queue<int> q;
        int time = 0;
        int vis[100001];
        memset(vis,0,sizeof(vis));
        vis[start] = 1;
        q.push(start);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int p = q.front(); q.pop();
                for(auto &adj : map[p]) {
                    if(!vis[adj]) {
                        q.push(adj);
                        vis[adj] = 1;
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};