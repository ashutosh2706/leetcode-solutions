class Solution {
private:
int dfs(int node, vector<vector<int>> &graph, vector<int> &time) {

    int ans = 0;
    for(auto &adj:graph[node]) 
        ans = max(ans, time[node] + dfs(adj,graph,time));
    return ans;

}
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& times) {

        int head = headID;
        vector<vector<int>> graph (n, vector<int>{});
        for(int i=0; i<n; i++) {
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }

        return dfs(headID, graph, times);
    }
};