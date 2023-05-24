class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // topological sort
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> indeg(n),res;
        for(int i=0; i<n; i++) {
            for(auto &node : adj[i]) indeg[node]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) if(indeg[i]==0) q.push(i);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front(); q.pop();
                for(auto &i:adj[node]) {
                    if(--indeg[i] == 0) q.push(i);
                }
                res.push_back(node);
            }
        }
        return res.size()==n ? res : vector<int>{};
    }
};