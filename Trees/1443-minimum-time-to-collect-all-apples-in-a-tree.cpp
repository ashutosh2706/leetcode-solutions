class Solution {
public:
    int vis[100004];
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int, vector<int>> graph;
        for(auto &v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        dfs(0, graph, hasApple);
        return 2*sum;
    }

    int sum = 0;
    int dfs(int node, unordered_map<int, vector<int>> &graph, vector<bool> &apples) {
        
        if(graph[node].size() == 0) {
            return apples[node] == true;
        }
        
        bool b = 0;
        for(auto &adj : graph[node]) {
            if(!vis[adj]) {
                vis[adj] = 1;
                int i = dfs(adj, graph, apples);
                if(i) sum++;
                b = b or i;
            }
        }
        b = b or apples[node];
        return b;
    }
};