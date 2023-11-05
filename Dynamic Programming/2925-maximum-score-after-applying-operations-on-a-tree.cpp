class Solution {
public:
    #define ll long long int
    ll dp[20001][2];
    unordered_map<int, vector<int>> graph;
    
    ll DFS(int node, vector<int> &values, int par, int skipped) {
        if(node != 0 and graph[node].size() == 1) {
            return skipped ? values[node] : 0;
        }
    
        if(dp[node][skipped] != -1) return dp[node][skipped];
        ll take = values[node];
        for(auto &c : graph[node]) {
            if(c != par)
            take += DFS(c,values,node,skipped);
        }

        ll skip = 0;
        for(auto &c : graph[node]) {
            if(c != par)
            skip += DFS(c,values,node,1);
        }
        return dp[node][skipped] = max(take, skip);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return DFS(0,values,-1,0);
    }
};