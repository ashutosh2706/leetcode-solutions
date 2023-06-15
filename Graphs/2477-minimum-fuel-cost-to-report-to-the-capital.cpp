class Solution {
private:
long long fuel = 0;
int dfs(int node, vector<vector<int>> &graph, int &seats, unordered_set<int> &vis) {
    vis.insert(node);
    int total = 1;
    for(auto &adj:graph[node]) {
        if(!vis.count(adj)) {
            total += dfs(adj,graph,seats,vis);
        }
    }
    fuel += ceil((double)total/(double)seats);
    return total;
}
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if(roads.size()==0) return 0;
        int n = roads.size();
        vector<vector<int>> adj;
        adj.resize(n+1);
        for(int i=0; i<n; i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        unordered_set<int> vis;
        vis.insert(0);
        for(auto &a:adj[0]) dfs(a,adj,seats,vis);
        return fuel;
    }
}; 