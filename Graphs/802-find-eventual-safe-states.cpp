class Solution {
private:
int dfs(int i, vector<vector<int>>& graph, vector<int>& vis) {
    if(vis[i] != -1) return vis[i];
    vis[i] = 0;
    bool b = 1;
    for(auto &adj : graph[i]) {
        if(b) 
            b = b and dfs(adj, graph, vis);
        else break;
    }
    return vis[i] = b;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                if(dfs(i,graph,vis)) res.push_back(i);
            }
            else if(vis[i] == 1) res.push_back(i);
        }
        return res;
    }
};