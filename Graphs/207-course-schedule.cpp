class Solution {
private:
    bool loop(int n, vector<int> adj[], vector<int>& vis) {
        if(vis[n] == 1) return true;
        if(vis[n] == 0) {
            vis[n] = 1;
            for(auto a:adj[n]) {
                if(loop(a, adj, vis)) return true;
            }
        }
        vis[n] = 2;
        return false;
    }
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        if(num == 1 || pre.size() == 0) return true;
        vector<int> vis(num, 0);
        vector<int> adj[num];
        for(vector<int> v:pre) adj[v[1]].push_back(v[0]);
        for(int i=0; i<num; i++) if(loop(i, adj, vis)) return false;
        return true;
    }
};