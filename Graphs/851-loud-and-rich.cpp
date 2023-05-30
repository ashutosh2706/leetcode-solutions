class Solution {
private:
int dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &quiet) {
    if(vis[node]!=-1) return vis[node];
    int min_quiet = quiet[node];
    for(auto &adj:graph[node]) {
        min_quiet = min(min_quiet, dfs(adj,graph,vis,quiet));
    } 
    return vis[node] = min_quiet;
}
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        map<int,int> map;
        int n = quiet.size();
        for(int i=0; i<quiet.size(); i++) map[quiet[i]] = i;
        vector<vector<int>> adj(n, vector<int>{});
        vector<int> vis(n,-1);
        for(auto &v:richer) adj[v[1]].push_back(v[0]);
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) 
                dfs(i,adj,vis,quiet);
        }
        for(int i=0; i<n; i++) vis[i] = map[vis[i]];
        return vis;
    }
};