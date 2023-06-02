class Solution {
#define ll long long
private:
long long dist(ll x1, ll y1, ll x2, ll y2) {
    return pow(x2-x1,2) + pow(y2-y1,2);
}
void dfs(int node, vector<vector<int>>& graph, unordered_set<int> &vis) {
    vis.insert(node);
    for(auto &adj : graph[node]) {
        if(vis.count(adj) == 0)
            dfs(adj,graph,vis);
    }
}
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<vector<int>> graph(n, vector<int>{});
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                ll x1 = bombs[i][0], y1 = bombs[i][1];
                ll x2 = bombs[j][0], y2 = bombs[j][1];
                ll r = bombs[i][2];
                if(dist(x1,y1,x2,y2) <= (ll)(r*r)) graph[i].push_back(j);
            }
        }

        int ans = 0;
        unordered_set<int> vis;
        for(int i=0; i<n; i++) {
            dfs(i,graph,vis);
            ans = max(ans, (int)vis.size());
            vis.clear();
        }
        return ans;
    }
};